#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long int ll;
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define  ff          first
#define  ss          second
#define  pb          push_back
#define  IOS         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define  lb          lower_bound
#define  ub          upper_bound
#define  D2(x)       { cerr << "[" << #x << ": "; for(auto it:x) cerr << it << " "; cerr << "]\n"; }
#define  all(x)      (x).begin(), (x).end()
#define  mem(a)      memset(a , 0 ,sizeof a)
#define  deb(x)      cout << #x << " - " << x << "\n";
#define  ps(x,y)     fixed<<setprecision(y)<<x
#define  setbit(x)  __builtin_popcountll(x)
#define  deb2(x,y)   cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n"
#define  rep(i,a,b)  for(int i=a ; i<b ; ++i)
#define  repr(i,a,b)  for(int i=a ; i>=b ; --i)
 
#define PI 3.141592653589793
const ll p = 5;
const ll INF = 1000000000;
const ll MAX_N = 2e5 + 2;

vi adj[MAX_N],vis(MAX_N),curr_t(MAX_N),nodes,in_tm(MAX_N),out_tm(MAX_N),idx(MAX_N);
int cntr = 1;

void dfs(int node){
    vis[node] = 1;
    nodes.pb(node);
    idx[node] = (int)nodes.size()-1;
    curr_t[cntr] = node;
    in_tm[node] = cntr++;
    
    for(auto x:adj[node]){
        if(!vis[x]) dfs(x);
    }
    out_tm[node] = cntr;
}

int main() {
    IOS;
    int n,q; cin >> n >> q;
    
    int na,nb; 
    rep(i,1,n){
        cin >> na >> nb;
        adj[na].pb(nb), adj[nb].pb(na);
    }
    
    dfs(1);
    
    vll d(n+1),a(n);
    d[0] = d[n] = 0;
    rep(i,1,n) d[i] = a[i] - a[i-1];
    
    while(q--){
        int vertex,x; cin >> vertex >> x;
        int id = idx[vertex],sz = abs(in_tm[vertex] - out_tm[vertex]);
        
        // deb(id);
        d[id] += x;
        d[id + sz] -= x;
    }
    
    a[0] = d[0]; 
    rep(i,1,n) a[i] = d[i] + a[i - 1]; 
    
    rep(i,1,n+1) cout << a[idx[i]] << ' ';
}