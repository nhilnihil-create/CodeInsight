#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
    int n,s;cin>>n>>s;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(s+1));
    dp[0][0] = 1;
    rep(i,0,n){
        rep(j,0,s+1){
            dp[i+1][j]+=dp[i][j]*2%mod2;
            if (j-a[i]>=0){
                dp[i+1][j]+=dp[i][j-a[i]]%mod2;
            }
            dp[i+1][j]%=mod2;
        }
    }
    cout<<dp[n][s]%mod2<<endl;
}