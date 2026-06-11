#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,mod=1e9+7;
string s;
ll dp[N][2],n;
ll func(ll idx,ll flg){
    if(idx==n)return 1;
    if(dp[idx][flg]!=-1)return dp[idx][flg];
    ll &ans = dp[idx][flg];
    if(flg==0){
        if(s[idx]=='0')ans=func(idx+1,0);
        else ans = func(idx+1,1) + (2ll*func(idx+1,0))%mod;
    }
    else ans = 3ll*func(idx+1,1);
    ans%=mod;
    return ans;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>s;n=s.size();
    cout<<func(0,0);
}