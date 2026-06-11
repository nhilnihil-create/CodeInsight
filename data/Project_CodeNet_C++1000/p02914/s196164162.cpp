#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<long long> a(n); long long all = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; all ^= a[i];
    }
    long long x = ~all;
    for (int i = 0; i < n; i++) a[i] &= x;
    sort(a.rbegin(), a.rend());
    int base = 0;
    for (int k = 60; k >= 0; k--) {
        for (int i = base; i < n; i++) {
            if (a[i] & (1LL << k)) {
                swap(a[i], a[base]);
                break;
            }
        }
        if (a[base] & (1LL << k)) {
            for (int i = 0; i < n; i++) {
                if (i == base) continue;
                if (a[i] & (1LL << k)) {
                    a[i] ^= a[base];
                }
            }
            base++;
        }
    }
    long long an = 0;
    for (int i = 0; i < n; i++) {
        if (an ^ a[i] > an) an = an ^ a[i];
    }
    cout << an * 2 + all << endl;
    return 0;
}