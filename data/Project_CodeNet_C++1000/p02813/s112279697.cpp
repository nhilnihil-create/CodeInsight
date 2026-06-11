#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
const int MOD = 1e9 + 7;

int main() {
    ll n, a, b;
    cin >> n;
    vector<int>p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    ll ans = 0;
    vector<int> one_case;
    for (int i = 1; i <= n; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case.emplace_back(i);
    }
    int c = 0;
    do {
        bool ok = 1;
        rep(i, n) {
            if (one_case[i] != p[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            a = c;
        }
        ok = 1;
        rep(i, n) {
            if (one_case[i] != q[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            b = c;
        }
        c++;
    } while (next_permutation(one_case.begin(), one_case.end()));
    cout << abs(a - b) << endl;
    return 0;
}
