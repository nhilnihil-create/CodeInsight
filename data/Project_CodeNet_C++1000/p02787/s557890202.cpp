#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

int a[1005],b[1005];
int dp[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,h,i,j;
    cin>>h>>n;
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
        for(j=0;j<=h;j++){
            dp[min(j+a[i],h)]=min(dp[min(j+a[i],h)],dp[j]+b[i]);
        }
    }
    cout<<dp[h];
    return 0;
}