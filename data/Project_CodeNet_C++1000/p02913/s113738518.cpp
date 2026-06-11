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

int dp[5005][5005];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i] != s[j]) dp[i][j] = 0;
            else dp[i][j] = dp[i + 1][j + 1] + 1;
        }
    }

    int res = 0;
    rep(i, n) {
        rep(j, n) {
            if (i >= j) continue;
            int now = min(dp[i][j], j - i);
            chmax(res, now);
        }
    }
    cout << res << endl;

    return 0;
}