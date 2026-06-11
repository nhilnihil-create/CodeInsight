#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int dp[3005][3005];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> p(n);
    rep(i, n) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());

    int ans = 0;
    rep(i, n) {
        rep(j, t) {
            chmax(dp[i + 1][j], dp[i][j]);
            int nj = j + p[i].first;
            if (nj < t) chmax(dp[i + 1][nj], dp[i][j] + p[i].second);
        }
        int now = dp[i][t - 1] + p[i].second;
        chmax(ans, now);
    }

    cout << ans << endl;

    return 0;
}