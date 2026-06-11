#include<bits/stdc++.h>
using namespace std;
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
const long long mod = 1e9+7;
int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<bool> ok(n+1,true);
    REP(i,0,m){
        int a;
        cin >> a;
        ok[a] = false;
    }
    vector<long long> dp(n+1);
    dp[0]=1;
    REP(now,0,n)REP(next,now+1,min(n,now+2)+1){
        if(ok[next]){
            dp[next] += dp[now];
            dp[next] %= mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
