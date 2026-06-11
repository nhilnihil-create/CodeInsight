//Ki

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int n,q;
graph g;
vector<int>d;
vector<bool>seen;
map<int,int>m{};

int dfs(int t,int o){
    if(seen[t])return 0;
    else seen[t]=true;
    d[t]=d[o]+m[t];
    for(auto i:g[t]){
        dfs(i,t);
    }
    return 0;
}

signed main (){
    cin>>n>>q;
    g.resize(n+1);
    d.resize(n+1);
    seen.resize(n+1);
    rep(i,0,n+1){
        d[i]=0;
        seen[i]=false;
    }
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    rep(i,0,q){
        int a,b;cin>>a>>b;
        m[a]+=b;
    }
    dfs(1,0);
    rep(i,1,n+1){
        cout<<d[i]<<nnn;
    }
    return 0;
}