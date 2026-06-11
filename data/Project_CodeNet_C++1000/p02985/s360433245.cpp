#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 2e5+5;
const ll mod = 1e9+7;
vector<int>v[N];
int n,k;
ll fac[N];
ll inv[N];
ll po(ll a, ll b){
    if(b==0)return 1;
    ll x = po(a,b/2);
    x = (x*x)%mod;
    if(b&1)x = (x*a)%mod;
    return x;
}
ll nck(ll a, ll b){
    if(b>a)return 0;
    ll ret = (fac[a]*inv[b])%mod;
    ret = (ret*inv[a-b])%mod;
    return ret;
}
ll dp[N];
bool vis[N];
int root = 0;
void dfs(int x){
    vis[x] = true;
    int cnt = k-2;
    if(x==root)cnt++;
    dp[x] = 1;
    int chld = 0;
    for(int y:v[x]){
        if(vis[y])continue;
        dfs(y);
        chld++;
        dp[x] = (dp[x]*dp[y])%mod;
    }
    dp[x] = (dp[x]*nck(cnt,chld))%mod;
    dp[x] = (dp[x]*fac[chld])%mod;
}
void solve(){
    cin>>n>>k;
    fac[0] = 1;
    for(int i=1;i<=k;i++){
        fac[i] = fac[i-1]*i;
        fac[i]%=mod;
    }
    inv[k] = po(fac[k],mod-2);
    for(int i=k-1;i>=0;i--){
        inv[i] = inv[i+1]*(i+1);
        inv[i]%=mod;
    }
    int x,y;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i=1;i<=n;i++){
        if(v[i].size()==1){
            root = i;
            break;
        }
    }
    dfs(root);
    dp[root] = (dp[root]*k)%mod;
    cout<<dp[root]<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
  //  cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
