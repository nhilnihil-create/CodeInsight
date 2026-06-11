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

ll dp[1000002][2];
int main()
{
    string N;
    cin >> N;
    dp[0][1] = 1;

    rep(i, N.size()) {
        ll num = N[i] - '0';
        dp[i + 1][0] = min(dp[i][0] + num, dp[i][1] + (10 - num));
        dp[i + 1][1] = min(dp[i][0] + num + 1, dp[i][1] + (9 - num));
    }
    cout << dp[(int)N.size()][0] << endl;
    return 0;
}