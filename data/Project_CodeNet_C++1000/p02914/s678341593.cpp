#include <algorithm>
#include <iostream>
using namespace std;
using ull = unsigned long long;
bool check(ull* b, int n, int k, ull c) {
    ull a = 0;
    for (int j = k-1, i0 = 0; j >= 0; j--) {
        for (int i = i0; i < n; i++) {
            if ((b[i] >> j) & 1) {
                swap(b[i], b[i0]);
                const ull mask = b[i0] ^ (1LL<<j);
                for (int m = i0+1; m < n; m++)
                    if ((b[m] >> j) & 1) b[m] ^= mask;
                if ((c >> j) & 1) c ^= mask;
                i0++;
                a ^= 1LL << j;
                break;
            }
        }
    }
    return (a & c) == c;
}

int main() {
    int n; cin >> n;
    ull a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    ull A = 0;
    for (ull x : a) A ^= x;
    for (ull &x : a) x &= ~A;

    ull ans = 0;
    for (int k = 1; k <= 60; k++) {
        ull tmp[n];
        for (int i = 0; i < n; i++) tmp[i] = a[i] >> (60 - k);
        if (check(tmp, n, k, 2 * ans + 1)) ans = 2 * ans + 1;
        else ans = 2 * ans;
    }
    cout << ans * 2 + A << endl;
}
