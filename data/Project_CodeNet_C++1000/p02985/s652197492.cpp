#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fill(a,c) memset(&a, c, sizeof(a))
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI 3.1415926535897932384626433832795
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

int n,k;
const int MAXN = 1e5+5;
vector<int> g[MAXN];
ll ans = 0, mod = 1e9+7;

void dfs(int u, int p){
    ll cnt = k-1;
    if(p != -1) cnt--;
    for(auto v: g[u]){
        if(v == p) continue;
        ans*=cnt;
        ans%=mod;
        cnt--;
        dfs(v,u);
    }
}

int main() {FIN;
    cin>>n>>k;
    fore(i,0,n-1){
        int u,v; cin>>u>>v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    ans = k;
    dfs(0,-1);
    cout<<ans<<"\n";
    return 0;
}

