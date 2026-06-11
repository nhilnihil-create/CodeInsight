#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    
    cin >> a >> b >> c;
    
    if (a < b && a < c) {
        if (b < c) {
            cout << a << " " << b << " " << c << "\n";
        } else {
            cout << a << " " << c << " " << b << "\n";
        }
    } else if (b < c) {
        if (a < c) {
            cout << b << " " << a << " " << c << "\n";
        } else {
            cout << b << " " << c << " " << a << "\n";
        }
    } else {
        if (a < b) {
            cout << c << " " << a << " " << b << "\n";
        } else {
            cout << c << " " << b << " " << a << "\n";
        }
    }
    
    return 0;
}