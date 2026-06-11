#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int mod = 1000000007;
ll ans;
vector<int> seen;
int n,k;

ll perm(ll a, ll b){
    ll x = 1;
    rep(i,b){
        (x*=a-i)%=mod;
    }
    return x;
}

void dfs(vector<vector<int>> &G,int p, int dep){
    seen[p] = dep;
    if(k-min(dep,2)<G[p].size()-min(dep-1,1)){ans = 0; return;}
    ans *= perm(k-min(dep,2),G[p].size()-min(dep-1,1));
    ans %= mod;
    for(int next:G[p]){
        if(seen[next]!=-1)continue;
        else dfs(G,next, dep+1);
    }
    return;
}

int main(){
    cin >> n >> k;
    vector<vector<int>> G(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans = k;
    seen.resize(n,-1);
    dfs(G,0,1);
    cout << ans << endl;
    return 0;
}