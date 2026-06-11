#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    vector<ll> dp(n+1),a(n);
    rep(i,0,m){
        int b;cin>>b;
        a[b-1] = 1;
    }
    dp[0] = 1;
    if (a[0]==0) dp[1] = 1;
    rep(i,1,n){
        if (a[i]!=1){
            dp[i+1] = (dp[i]+dp[i-1])%mod;
        }
    }
    cout<<dp[n]<<endl;
}