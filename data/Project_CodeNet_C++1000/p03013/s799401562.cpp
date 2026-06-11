#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<bool> ok(n+1,true);
    rep(i,m){
        int a;
        cin >> a;
        ok[a] = false;
    }
    vector<long long> dp(n+1);
    dp[0]=dp[1]=1;
    if(ok[1]==false) dp[1]--;
    REP(i,2,n+1){
        if(!ok[i]) dp[i] = 0;
        else dp[i] = ((dp[i-1]%mod)+(dp[i-2]%mod))%mod;
        dp[i] %= mod;
    }
    cout << dp[n] << endl;
    return 0;
}
