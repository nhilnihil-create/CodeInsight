#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, n) for (ll i = n-1; i >= 0; i--)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repd2(i, s, n) for (ll i = n-1; i >= (s); i--)

int main() {
    int d;
    cin >> d;
    vector<int> c(26);
    rep(i, 26) cin >> c[i];
    vector<vector<int>> s(d, vector<int>(26));
    rep(i, d) {
        rep(j, 26) cin >> s[i][j];
    }

    vector<int> t(d);
    rep(i, d) cin >> t[i];

    vector<int> prev(26, -1);
    int ans = 0;
    rep(i, d){
        ans += s[i][t[i]-1];
        prev[t[i]-1] = i;
        rep(j, 26){
            ans -= c[j] * (i - prev[j]);
        }

        cout << ans << endl;
    }

    return 0;
}