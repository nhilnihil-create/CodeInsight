#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=3e3+10;
int n,t;
pii v[mxN];
int dp[mxN][mxN];
int solve(int obj,int aguenta){
    if(obj<0)return 0;
    if(!aguenta)return dp[obj][aguenta]=0;
    if(dp[obj][aguenta]>=0)return dp[obj][aguenta];

    int naoc=solve(obj-1,aguenta);
    if(v[obj].first<=aguenta){
        int col=solve(obj-1,aguenta-v[obj].first)+v[obj].second;

        return dp[obj][aguenta]=max(naoc,col);
    }
    return dp[obj][aguenta]=naoc;
}
int main(){
    memset(dp,-1,sizeof(dp));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    t--;
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v,v+n);
    solve(n-1,t);
    ll ans = (ll)(dp[0][t]);
    for(int i=1;i<n;i++){
        ans=max(ans,(ll)dp[i-1][t]+v[i].second);
    }
    cout<<ans;
}