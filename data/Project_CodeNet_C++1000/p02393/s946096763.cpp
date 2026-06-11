#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    auto cswap = [] (int& x, int& y) { if (x > y) { int tmp = x; x = y;  y = tmp; } };
    cswap(a, b);
    cswap(b, c);
    cswap(a, b);
    cout << a << " " << b << " " << c << endl; 
}