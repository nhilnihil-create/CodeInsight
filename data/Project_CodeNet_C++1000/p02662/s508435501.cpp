#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,s,i,j,k=1,m=998244353;
    cin>>n>>s;
    ll dp[n+1][s+1];
    ll ar[n+1];
    for(i=1;i<=n;i++)
        cin>>ar[i];
    for(i=0;i<=n;i++){
        for(j=0;j<=s;j++){
            if(i==0)
                dp[i][j]=0;
            if(j==0){
                dp[i][j]=k%m;
                k=((k%m)*(2%m))%m;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=s;j++){
            if(ar[i]<=j)
                dp[i][j]=((dp[i-1][j-ar[i]]%m)+(2*(dp[i-1][j])%m)%m);
            else
                dp[i][j]=(2*(dp[i-1][j]%m)%m);
        }
    }
    cout<<dp[n][s]%m<<endl;
}
