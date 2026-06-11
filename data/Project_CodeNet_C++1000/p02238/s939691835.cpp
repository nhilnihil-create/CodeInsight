#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;
//#define int ll
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<V<T>>;
#define fi first
#define se second
#define maxs(x,y) (x=max(x,y))
#define mins(x,y) (x=min(x,y))
using pii = pair<int,int>; using pll = pair<ll,ll>;
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(ll i = (ll)(b)-1;i >= a;--i)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define eb(val) emplace_back(val)
const double PI = acos(-1), EPS = 1e-10;
const ll MOD = 1e9+7;
int t=0;
vi d,f;
vb used;
void dfs(int now,vvi &gr){
  if(used[now]) return;
  used[now] = true;
  t++;
  mins(d[now],t);
  REP(i,gr[now].size()){
    dfs(gr[now][i],gr);
  }
  t++;
  f[now] = t;
}
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  d.assign(n,INT_MAX);
  f.assign(n,INT_MAX);
  used.assign(n,false);
  vvi gr(n);
  REP(i,n){
    int k;
    cin >> k >> k;
    REP(j,k){
      int v;
      cin >> v;
      gr[i].eb(v-1);
    }
  }
  REP(i,n){
    dfs(i,gr);
  }
  REP(i,n){
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }
}

