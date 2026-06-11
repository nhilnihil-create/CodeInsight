#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    rep(i, n) cin >> a.at(i);
    rep(i, m) cin >> b.at(i);

    ll t = 0;
    rep(i, m) t += b.at(i);

    int j = m;
    int ans = 0;
    rep(i, n + 1) {
        while (j > 0 && t > k) {
            j--;
            t -= b.at(j);
        }
        if (t > k) break;
        ans = max(ans, i + j);
        if (i == n) break;
        t += a.at(i);
    }

    cout << ans << endl;

    return 0;
}
