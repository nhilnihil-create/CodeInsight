#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "Yes" << endl;
        return 0;
    }

    for (int i = 2; i < 10; i++) {
        if (n / i < 10 && n % i == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}