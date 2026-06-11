#pragma gcc optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int nax = 1e6 + 1;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> spf(nax);
    for (ll i = 2; i < nax; ++i) {
        if (!spf[i]) {
            spf[i] = i;
            for (ll j = i * i; j < nax; j += i) {
                if (!spf[j]) spf[j] = i;
            }
        }
    }
    int n; cin >> n;
    int pc = 1, sc = 0;
    bitset<nax> f;
    vector<int> v;
    auto fail = [&] (int x) {
        v.clear();
        while (x > 1) {
            int t = spf[x];
            // cout << t << ' ';
            if (f[t]) return 1;
            v.emplace_back(t);
            x /= t;
        }
        for (auto p : v) f[p] = 1;
        return 0;
    };
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        // cout << i << ": ";
        if (fail(a)) pc = 0;
        sc = gcd(sc, a);
        // cout << '\n';
    }
    if (pc) cout << "pairwise coprime\n";
    else if (sc == 1) cout << "setwise coprime\n";
    else cout << "not coprime\n";
}