#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    ll ans = 0;
    vector<bool> dp(n, false);
    rep(i, n) {
        ll bef = i - k;
        if ((bef < 0) || ((t[bef] != t[i]) || (!dp[bef]))) {
            if (t[i] == 'r') {
                ans += p;
            }
            else if (t[i] == 's') {
                ans += r;
            }
            else {
                ans += s;
            }
            dp[i] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
