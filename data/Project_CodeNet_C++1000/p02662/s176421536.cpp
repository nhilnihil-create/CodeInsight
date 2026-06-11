#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=998244353;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n,s;
    cin>>n>>s;
    int a[n];
    rep(i,n)cin>>a[i];
    ll dp[n+1][s+1]={};
    dp[0][0]=1;
    rep(i,n){
        for(int j=0;j<=s;++j){
            (dp[i+1][j]+=2*dp[i][j])%=mod;
            if(j+a[i]<=s){
                (dp[i+1][j+a[i]]+=dp[i][j])%=mod;
            }
        }
    }
    cout<<dp[n][s]<<endl;
}
