#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+50;
typedef long long ll;
int n;
ll a[maxn],dp[maxn];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    dp[1]=1000;
    for(int i=1;i<=n;++i){
        dp[i+1]=max(dp[i],dp[i]/a[i]*a[i+1]+dp[i]%a[i]);
    }
    cout<<dp[n]<<endl;
    return 0;
}