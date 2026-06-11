#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define debug(x) cerr <<__LINE__<< ": " <<#x<< " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int dp[101010][3];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> P(3);
    for(auto &p : P) cin >> p;
    string t;
    cin >> t;
    int ans = 0;
    rep(idx, k) {
        int x = idx;
        string str;
        while(x < n) {
            str += t[x];
            x += k;
        }
        int m = str.size();
        rep(j, m + 1) rep(a, 3) dp[j][a] = 0;
        rep(i, m) {
            rep(a, 3) rep(b, 3) {
                if (a == b) continue;
                if ((str[i] == 'r' && a == 2) ||
                    (str[i] == 's' && a == 0) ||
                    (str[i] == 'p' && a == 1)) {
                    chmax(dp[i + 1][a], dp[i][b] + P[a]);
                } else {
                    chmax(dp[i + 1][a], dp[i][b]);
                }
            }
        }
        ans += *max_element(dp[m], dp[m] + 3);
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
