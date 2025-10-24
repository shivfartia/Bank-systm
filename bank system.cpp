#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNo, double initialBalance) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully!\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        } else {
            cout << "Invalid or insufficient balance.\n";
        }
    }

    
    void display() {
        cout << "\n----- Account Details -----\n";
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: ₹" << balance << endl;
        cout << "-----------------------------\n";
    }

    
    int getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    string name;
    int accNo;
    double balance;
    int choice;
    double amount;

    cout << "Enter Account Holder Name: ";
    getline(cin, name);
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Initial Balance: ₹";
    cin >> balance;

    BankAccount acc(name, accNo, balance);

    do {
        cout << "\n------ Bank Menu ------\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "-----------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ₹";
            cin >> amount;
            acc.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ₹";
            cin >> amount;
            acc.withdraw(amount);
            break;
        case 3:
            cout << "Your current balance is: ₹" << balance << endl;
            break;
        case 4:
            acc.display();
            break;
        case 5:
            cout << "Thank you for using our HDFC bank.!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
