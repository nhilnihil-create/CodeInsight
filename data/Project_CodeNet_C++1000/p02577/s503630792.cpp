#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    char c;
    while(cin >> c) {
        sum += c - '0';
    }
    if (sum % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
