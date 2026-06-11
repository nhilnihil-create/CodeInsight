/*
  Reference:-
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define PI pair<int,int>
#define all(vec) vec.begin(),vec.end()
//ll mod=1000000007;
ll mod=998244353;
const int N=2e5 + 5;
ll power(ll n,ll k){
    ll ans=1;
    while(k){
        if(k&1)ans=(ans*n)%mod;
        k/=2;
        n=(n*n)%mod;
    }
    //ans=(ans-1+mod)%mod;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,s;
    cin>>n>>s;
    int ar[n];
    forn(i,n)cin>>ar[i];
    ll dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=power(2,n);
    ll inv=power(2,mod-2);
    forn(j,s+1){
        forn1(i,n+1){
            dp[i][j]=dp[i-1][j];
            if(j-ar[i-1]>=0){
                ll temp=(dp[i-1][j-ar[i-1]]*inv)%mod;
                dp[i][j]=(dp[i][j]+temp)%mod;
            }
            //dp[i][j]+=dp[i-1][j];
        }
    }
    //forn(i,n+1){forn(j,s+1)cout<<dp[i][j]<<" ";cout<<endl;}
    cout<<dp[n][s];

    return 0;
}
