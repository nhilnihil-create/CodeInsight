#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
const long long MOD = 1e9 + 7;
int main()
{
    string L;
    cin >> L;

    int N = (int)L.size();
    vector<vector<ll>> dp(N + 1, vector<ll>(2, 0));
    dp[0][0] = 1;

    rep(i, N) {
        int n = L[i] - '0';
        rep(j, 2) {
            for (int d = 0; d <= (j ? 1 : n); d++) {
                int k = (d ? 2 : 1);
                dp[i + 1][j || (d < n)] += dp[i][j] * k;
                dp[i + 1][j] %= MOD;
            }
        }
    }

    cout << (dp[N][0] + dp[N][1]) % MOD << endl;
    return 0;
}