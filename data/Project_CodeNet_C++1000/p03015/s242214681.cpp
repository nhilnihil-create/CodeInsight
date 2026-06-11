#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

const ll mod =1e9+7;

int main() {
    string l;
    cin>>l;
    ll n=l.size();
    vector<vector<ll>> dp(n,vector<ll>(2));
    dp[0][1]=1; 
    dp[0][0]=2;

    rep(i,n-1){
        if(l[i+1]=='1'){
            dp[i+1][1]=(dp[i][1]*3+dp[i][0])%mod;
            dp[i+1][0]=dp[i][0]*2%mod;
        }else{
            dp[i+1][1]=dp[i][1]*3%mod;
            dp[i+1][0]=dp[i][0]%mod;
        }
    }
    cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
    return 0;
}

