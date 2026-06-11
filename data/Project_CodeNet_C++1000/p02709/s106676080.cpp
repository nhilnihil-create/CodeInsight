#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll dp[2001][2001],n,a,ans;
vector<P> v;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back({a,i});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++){
        dp[i+1][0]=dp[i][0]+v[i].first*abs(v[i].second-i);
        dp[0][i+1]=dp[0][i]+v[i].first*abs(n-v[i].second-1-i);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(i+j>n)continue;
            dp[i][j]=max(dp[i-1][j]+v[i+j-1].first*abs(v[i+j-1].second-i+1),dp[i][j-1]+v[i+j-1].first*abs(n-v[i+j-1].second-1-j+1));
        }
    }
    for(int i=0;i<=n;i++){
        ans=max(ans,dp[i][n-i]);
    }
    cout<<ans<<endl;
}
