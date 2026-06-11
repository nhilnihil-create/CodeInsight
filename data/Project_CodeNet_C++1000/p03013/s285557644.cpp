#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> dp(N+1,-1);
    rep(i,M) {
        int a;
        cin >> a;
        dp[a] = 0;
    }
    dp[0] = 1;
    rep(i,N) {
        if (dp[i+1]==0) continue;
        if (i==0) dp[i+1]=dp[i];
        else {
            dp[i+1] = dp[i]+dp[i-1];
            dp[i+1] %= MOD;
        }
    }
    cout << dp[N] << endl;
}
