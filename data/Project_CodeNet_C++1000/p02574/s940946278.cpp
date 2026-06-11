#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = 1e6;
    vector<int> z(mx + 1);
    for (int i = 2; i * i <= mx; i++) {
        if (!z[i]) {
            for (int j = i * i; j <= mx; j += i) {
                z[j] = 1;
            }
        }
    }
    vector<int> p;
    for (int i = 2; i <= mx; i++) {
        if (!z[i]) {
            p.push_back(i);
        }
    }
    int s = p.size(), g = a[0];
    vector<int> c(mx + 1);
    bool f = true;
    for (int i = 0; i < n; i++) {
        g = __gcd(g, a[i]);
        for (int j = 0; j < s && p[j] * p[j] <= a[i]; j++) {
            if (a[i] % p[j] == 0) {
                if (c[p[j]]) {
                    f = false;
                }
                c[p[j]] = 1;
                while (a[i] % p[j] == 0) {
                    a[i] /= p[j];
                }
            }
        }
        if (a[i] > 1) {
            if (c[a[i]]) {
                f = false;
            }
            c[a[i]] = 1;
        }
    }
    cout << (f ? "pairwise coprime" : g == 1 ? "setwise coprime" : "not coprime") << endl;
    return 0;
}
