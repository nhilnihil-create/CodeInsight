//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i,n,s) for (int i= (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

ll modpow(ll a, ll b){
    ll r = 1;
    while(b){
        r = r*((b%2)?a:1)%mod;
        a = a*a%mod;
        b>>=1;
    }
    return r;
}

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    string l;cin>>l;
    ll s = l.size();
    vector<vector<ll>> dp(s+1,vector<ll>(2));
    dp[0][0] = 1;
    rep(i,0,s){
        dp[i+1][1] = dp[i][1]*3%mod;
        if (l[i]=='0'){
            dp[i+1][0] = (dp[i+1][0]+dp[i][0])%mod;
        }else{
            dp[i+1][1] = (dp[i+1][1]+dp[i][0])%mod;
            dp[i+1][0] = (dp[i+1][0]+dp[i][0]*2)%mod;
        }
    }
    cout<<(dp[s][0]+dp[s][1])%mod<<endl;;
}