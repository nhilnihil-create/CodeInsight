#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vll s(n), t(m);
    rep(i, 0, n) { cin >> s[i]; }
    rep(i, 0, m) { cin >> t[i]; }

    vll cols(m, 0);
    rep(i, 0, n) {
        ll sum = 0;
        rep(j, 0, m) {
            ll d = (s[i] == t[j]) ? (1 + sum) % MOD : 0;
            sum = (sum + cols[j]) % MOD;
            cols[j] = (cols[j] + d) % MOD;
        }
    }

    ll ans = 1;
    rep(i, 0, m) { ans = (ans + cols[i]) % MOD; }
    cout << ans << endl;

    return 0;
}