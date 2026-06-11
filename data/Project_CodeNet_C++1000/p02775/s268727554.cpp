#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#ifdef LOCAL
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define dump(x)
#define debug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

void solve(string & ns){
    int N = ns.size();
    vector<vector<int>> dp(N+1, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = 1;
    rep(i,1,N+1) {
        int digit = ns[i-1] - '0';
        dp[i][0] = min(dp[i-1][0] + digit, dp[i-1][1] + (10 - digit));
        dp[i][1] = min(dp[i-1][0] + (digit+1), dp[i-1][1] + (10 - (digit+1)));
    }
    cout << dp[N][0] << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    string N;
    cin >> N;
    solve(N);
    return 0;
}
