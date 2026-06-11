#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define INVALID -1
#define mod 1e9+7
#define rep(n) for(int i=0;i<n;++i)
using namespace std;
int main(void){
    // Your code here!

int n,m;

cin>>n>>m;
vector<ll> dp(n+1,0);
dp[0]=1;
dp[1]=1;
for(int i=0;i<m;i++){
    int a;
    cin>>a;
    dp[a]=INVALID;
}

for(int i=2;i<=n;i++){
    if(dp[i]!=INVALID){
        if(dp[i-1]!=INVALID)
            dp[i]+=(dp[i-1]);
        if(dp[i-2]!=INVALID)
            dp[i]+=dp[i-2];
            dp[i]=dp[i]%1000000007;
           // cout<<dp[i]<<" ";
    }
    
}
cout<<dp[n]%1000000007;
}
