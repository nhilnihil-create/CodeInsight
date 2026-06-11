#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    if (n < 3 || (n & (n-1)) == 0) { cout << "No\n"; return 0; }
    cout << "Yes\n1 2\n2 3\n";
    cout << 3 << ' ' << 1+n << '\n'
         << 1+n << ' ' << 2+n << '\n'
         << 2+n << ' ' << 3+n << '\n';
    for (int k = 4; k+1 <= n; k+=2)
        cout << k << ' ' << k+1 << '\n'
             << k+1 << ' ' << 1 << '\n'
             << 1 << ' ' << k+n << '\n'
             << k+n << ' ' << k+n+1 << '\n';
    if (n%2==0) {
        int a = n & (n-1), b = n - a;
        cout << a+1 << ' ' << n << '\n'
             << b+n << ' ' << 2*n << '\n';
    }
}
