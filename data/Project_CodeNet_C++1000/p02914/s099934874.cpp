#include <iostream>
using namespace std;
using ull = unsigned long long;
ull solve(ull* b, int n) {
    for (int j = 60, i0 = 0; j >= 0; j--) {
        for (int i = i0; i < n; i++) {
            if ((b[i] >> j) & 1) {
                swap(b[i], b[i0]);
                for (int m = 0; m < n; m++)
                    if (m != i0 && ((b[m] >> j) & 1)) b[m] ^= b[i0];
                i0++;
                break;
            }
        }
    }
    ull a = 0;
    for (int i = 0; i < n; i++) a ^= b[i];
    return a;
}

int main() {
    int n; cin >> n;
    ull a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    ull A = 0;
    for (ull x : a) A ^= x;
    for (ull &x : a) x &= ~A;
    cout << solve(a, n) * 2 + A << endl;
}
