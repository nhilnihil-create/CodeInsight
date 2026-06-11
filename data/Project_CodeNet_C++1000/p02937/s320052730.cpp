#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
//using namespace atcoder;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define all(x) (x).begin(),(x).end()
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
using Graph = vector<vector<ll>>;

// dijkstra　
struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    rep(i,V){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    rep(i,V){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};
// dijkstra end


class UnionFind
{
public:
  ll par[100005];
  ll depth[100005];
  ll nGroup[100005];
 
  UnionFind(ll n) {
    init(n);
  }
 
  void init(ll n) {
    for(ll i=0; i<n; i++) {
      par[i] = i;
      depth[i] = 0;
      nGroup[i] = 1;
    }
  }
 
  ll root(ll x) {
    if(par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }
 
  bool same(ll x, ll y) {
    return root(x) == root(y);
  }
 
  void unite(ll x, ll y) {
    x = root(x);
    y = root(y);
    if(x == y) return;
 
    if(depth[x] < depth[y]) {
      par[x] = y;
      nGroup[y] += nGroup[x];
      nGroup[x] = 0;
    } else {
      par[y] = x;
      nGroup[x] += nGroup[y];
      nGroup[y] = 0;
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};
// unionfind end

// nCr
const ll MAX = 500010;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// nCr end

// tree DP
vector<ll> depth;
vector<ll> g(10010,0);
ll c[10010];
void dfs(const Graph &G, ll v, ll p, ll &d) {
         g[v] = c[d-1];
    for (auto nv : G[v]) {
        if (nv == p) continue;
        d--;
        dfs(G, nv, v, d);
    }
}
// tree DP end
int main() {
  string s,t; cin>>s>>t;
  ll a[30]={};
  ll b[30]={};
  ll len = s.size();
  ll len1 = t.size();
  rep(i,len){
    a[s[i]-'a']++;}
  rep(i,len1){
    b[t[i]-'a']++;}
  rep(i,30){
    if(a[i]==0&&b[i]>0){
      cout << -1 << endl;
      return 0;}
  }
  vvl v(30);
  string ss = "";
  ss += s;
  ss += s;
  ll ca = -1;
  ll ans = 0;
  ll cb = -1;
  rep(i,len*2){
    v[ss[i]-'a'].pb(i);}
  rep(i,len1){
    if(i!=0) cb=ca;
    ll k = t[i]-'a';
    ll ok = v[k].size();
    
    //cout << v[k][1] << endl;
    ll ng = -1;
    while(abs(ok-ng)>1){
      ll mid = (ok+ng)/2;
      if(v[k][mid]>ca){
        ok = mid;}
      else
        ng = mid;}
    ca = v[k][ok];
    if(cb==ca){
      ca = v[k][ok+1];}
    if(ca>=len){
      ca-=len;
      ans+=len;}
  }
  cout << ans+ca+1 << endl;
}
    
        
    
  
