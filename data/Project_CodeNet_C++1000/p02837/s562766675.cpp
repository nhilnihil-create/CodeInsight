#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
using PII = pair<int, int>;
using VP  = vector<PII>;
using VVP = vector<VP>;
int n, a, x, y, res;
bool ok;
VVP v;
inline void Check(int mask) {
    int nrb = __builtin_popcount(mask);
    if (nrb <= res)
        return;
    for (int i = 0; i < n; ++i)
        if (mask & (1 << i))
            for (const PII& P : v[i]) {
                tie(x, y) = P;
                if ((!(mask & (1 << x)) && y) || ((mask & (1 << x)) && !y))
                    return;
            }
    res = nrb;
    return;
}
int main() {
    DAU
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v[i].resize(a);
        for (PII& P : v[i]) {
            cin >> P.first >> P.second;
            --P.first;
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask)
        Check(mask);
    cout << res;
    PLEC
}
