#include <iostream>
#include <vector>
#include <iomanip> // Untuk mengatur format output

using namespace std;

// Struktur untuk menyimpan informasi produk
struct Product {
    string name;
    double price;
};

// Fungsi untuk menampilkan menu produk
void displayMenu(const vector<Product>& products) {
    cout << "\nDaftar Produk:\n";
    for (int i = 0; i < products.size(); i++) {
        cout << i + 1 << ". " << products[i].name << " - Rp. " << fixed << setprecision(2) << products[i].price << endl;
    }
}

// Fungsi untuk menghitung total harga
double calculateTotal(const vector<Product>& products, const vector<int>& quantities) {
    double total = 0;
    for (int i = 0; i < products.size(); i++) {
        total += products[i].price * quantities[i];
    }
    return total;
}

// Fungsi untuk menghitung pajak
double calculateTax(double total, double taxRate) {
    return total * taxRate;
}

// Fungsi untuk menampilkan struk pembayaran
void printReceipt(const vector<Product>& products, const vector<int>& quantities, double total, double tax, double finalAmount) {
    cout << "\n--- STRUK PEMBAYARAN ---\n";
    for (int i = 0; i < products.size(); i++) {
        if (quantities[i] > 0) {
            cout << products[i].name << " x" << quantities[i] 
                 << " = Rp. " << fixed << setprecision(2) << products[i].price * quantities[i] << endl;
        }
    }
    cout << "\nTotal: Rp. " << fixed << setprecision(2) << total << endl;
    cout << "Pajak (10%): Rp. " << fixed << setprecision(2) << tax << endl;
    cout << "Total yang harus dibayar: Rp. " << fixed << setprecision(2) << finalAmount << endl;
    cout << "--------------------------\n";
}

int main() {
    // Daftar produk yang tersedia
    vector<Product> products = {
        {"Gearbox A", 1500000.00},
        {"Gearbox B", 2000000.00},
        {"Gearbox C", 2500000.00},
        {"Gearbox D", 3000000.00}
    };

    // Daftar kuantitas untuk produk yang dipilih oleh pengguna
    vector<int> quantities(products.size(), 0); // Semua kuantitas awalnya 0

    int choice;
    int quantity;
    double taxRate = 0.10; // Pajak 10%

    while (true) {
        displayMenu(products);  // Menampilkan menu produk

        cout << "\nMasukkan nomor produk untuk ditambahkan ke keranjang (0 untuk keluar): ";
        cin >> choice;

        if (choice == 0) {
            break;  // Keluar dari loop jika pengguna memilih 0
        }

        if (choice < 1 || choice > products.size()) {
            cout << "Pilihan tidak valid, coba lagi.\n";
            continue;
        }

        cout << "Masukkan jumlah (kuantitas) untuk " << products[choice - 1].name << ": ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Jumlah harus lebih besar dari 0.\n";
            continue;
        }

        quantities[choice - 1] += quantity;  // Menambahkan kuantitas produk ke keranjang
        cout << "\nProduk telah ditambahkan ke keranjang.\n";
    }

    double total = calculateTotal(products, quantities);  // Menghitung total harga
    double tax = calculateTax(total, taxRate);  // Menghitung pajak
    double finalAmount = total + tax;  // Total akhir yang harus dibayar

    // Menampilkan struk pembayaran
    printReceipt(products, quantities, total, tax, finalAmount);

    return 0;
}
