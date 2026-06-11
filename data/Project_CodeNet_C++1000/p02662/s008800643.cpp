#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define rep(i, j) FOR(i, 0, j, 1)
#define rrep(i, j) RFOR(i, j, 0, 1)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define endl "\n"
#define MOD 998244353
#define DEB(x) cout<<"##"<<x<<"##"<<endl;
ll fastex(int a,int b){
    if(b==0)
        return 1;
    ll t=fastex(a,b/2);
    if(b%2==0)
        return (t*t)%MOD;
    return (((t*t)%MOD)*a)%MOD;
}
ll modinv(int x){
    return fastex(x,MOD-2);
}
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
   int n,sum;
    cin>>n>>sum;
    int ar[n+1];
    //ar[0]=0;
    rep(i,n)
    cin>>ar[i];
    int dp[3005][3005]={0};
    dp[0][0]=fastex(2,n)%MOD;
    for(int i=0;i<n;i++){
        for(int j=0;j<=sum;j++){
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
            //cout<<dp[i+1][j]<<" ";

            if(j+ar[i]<=sum){
                dp[i+1][j+ar[i]]=(dp[i+1][j+ar[i]]+dp[i][j]*modinv(2))%MOD;
                //cout<<dp[i+1][j+ar[i]]<<" ";
            }
        }
        cout<<endl;
    }
   
    cout<<dp[n][sum];
    return 0;
}