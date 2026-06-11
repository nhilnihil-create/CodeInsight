#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
ll modpow(ll a, ll n){
  if(n==0)return 1;
  if(n%2==0){
    ll t=modpow(a,n/2);
    return t*t%MOD;
  }
  return a*modpow(a,n-1)%MOD;
}
ll modinv(ll a){
  return modpow(a,MOD-2);
}
long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
struct UnionFind {
    vector<int> par; // 親ノード
    vector<int> rank; // ランク
 
    UnionFind(int n = 1) {
        init(n);
    }
 
    void init(int n = 1) {
        par.resize(n); rank.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0;
    }
 
    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }
 
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
 
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};
vector<vector<P>> G;
vl ans;
void dfs(int v, int p=-1, int c=-1){
  int k=1;
  for(auto nv:G[v]){
    int next=nv.first,id=nv.second;
    if(next==p)continue;
    if(k==c)k++;
    ans[id]=k;
    k++;
    dfs(next,v,ans[id]);
  }
}
    
  
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  COMinit();
  
  ll n;
  cin >> n;
  G.resize(n);
  ans.resize(n-1);
  
  vector<ll>cnt(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(P(b,i));
    G[b].push_back(P(a,i));
    cnt[a]++;
    cnt[b]++;
  }
  dfs(0);
  ll m=*max_element(cnt.begin(),cnt.end());
  cout << m << endl;
  rep(i,n-1)cout << ans[i] << endl;
  return 0;
                   
    
  
}
