#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5;
string s;
ll dp[N][2],n;
ll solve(ll idx,ll carry){
    if(idx==n)return carry;
    ll &ans=dp[idx][carry];
    if(ans!=-1)return ans;
    ans = 1e15;
    ll val = s[idx]-'0'+carry;
    if(val<10)ans=min(ans,solve(idx+1,0)+val);
    ans=min(ans,solve(idx+1,1)+10-val);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    n=s.size();
    reverse(s.begin(),s.end());
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0);
}
