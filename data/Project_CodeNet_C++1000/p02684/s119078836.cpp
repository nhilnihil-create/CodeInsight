#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    ll n,k;
    cin>>n>>k;
    int a[n];
    rep(i,n){
        cin>>a[i];
        --a[i];
    }
    int dp[n][61];
    rep(i,n){
        dp[i][0]=a[i];
    }
    for(int i=1;i<=60;++i){
        rep(j,n){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    int t=0,now=0;
    while(k>0){
        if(k&1)now=dp[now][t];
        k/=2;
        ++t;
    }
    cout<<now+1<<endl;
}
