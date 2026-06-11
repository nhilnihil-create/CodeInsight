#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    long l, r;
    cin >> l >> r;
    long min_m = 2019;
    for (long i = l; i <= r - 1; i++) {
        for (long j = i + 1; j <= r; j++) {
            if (i % 2019 == 0 || j % 2019 == 0 || (i * j) % 2019 == 0) {
                min_m = 0;
                goto out;
            }
            long ij = (i * j) % 2019;
            min_m = min(ij, min_m);
        }
    }
    out:
    cout << min_m << endl;
}