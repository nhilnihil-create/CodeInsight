#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const int MOD = 1e9+7;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.length();
    
    vector<vector<int>> dp(n + 3, vector<int>(3, 0));
    dp[1][0] = dp[2][1] = 1;
    int res = 0;
    rep(i, n) {
        if (i >= 1 && s[i - 1] != s[i]) {
            chmax(dp[i + 1][1], dp[i][1] + 1);
        }
        if (i >= 2 && s[i - 2] != s[i] || s[i - 1] != s[i + 1]) {
            chmax(dp[i + 2][2], dp[i][2] + 1);
        }
        chmax(dp[i + 2][2], dp[i][1] + 1);
        chmax(dp[i + 1][1], dp[i][2] + 1);
    }

    cout <<  max(dp[n][1], dp[n][2]) << endl;

    return 0;
}