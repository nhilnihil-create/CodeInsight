#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
const int MOD=998244353;
int main(){
    int h,n;
    cin>>h>>n;
    vector<int> a(n),b(n),dp(h+1e5,1e9);
    rep(i,n) cin>>a[i]>>b[i];
    dp[0]=0;
    rep(i,h+1){
        rep(j,n){
            if(i+a[j]>=h){
                dp[h]=min(dp[h],dp[i]+b[j]);
                continue;
            }
            dp[i+a[j]]=min(dp[i]+b[j],dp[i+a[j]]);
        }
    }
    cout<<dp[h]<<endl;
    return 0;
}