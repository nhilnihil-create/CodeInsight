#include<bits/stdc++.h>
#define N 105
using namespace std;
typedef long long ll;
ll dp[N][N],n,h,a1,a2,ans;
ll find(ll x){
    while(x){
        if(x/10==0)return x;
        x/=10;
    }
}
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        h=i,a1=h%10,a2=find(h);
        dp[a2][a1]++;
    }
    for(ll i=1;i<=9;i++)
        for(ll j=1;j<=9;j++)
            ans+=dp[i][j]*dp[j][i];
    cout<<ans<<endl;
    return 0;
}