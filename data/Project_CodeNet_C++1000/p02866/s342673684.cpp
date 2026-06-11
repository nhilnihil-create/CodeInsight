#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1e17;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};
struct SegmentTree{
  int N;
  vector<int> node;
  public :
    void intit(vector<int>v){
      int sz = v.size();
      N=1;
      while(N<sz) N*=2;
      node.resize(N);
      for(int i=0 ; i<sz ; i++) node[i+N-1] = v[i];
      for(int i=N-2 ; i>=0 ; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }
    void update(int x, int val){
      x += N-1;
      node[x+N-1] = val;
      while(x>0){
        x = (x-1)/2;
        node[x] = min(node[x*2+1], node[x*2+2]);
      }
    }
    int getmin(int a, int b, int k, int l, int r){
      if(b<=l || r<=a) return inf;
      else if(a<=l && r<=b) return node[k];
      else{
        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
      }
    }
};
ll jow(ll n, ll x){
  ll res = 1;
  while(n){
    if(n & 1) res = res*x % mo;
    x = x*x%mo;
    n >>= 1LL;
  }
  return res;
}
int main(){
  int N;  cin>>N;
  bool isok=true;
  vector<int> v(N,0);
  rep(i,0,N){
    int x;  cin>>x;
    if(i==0) if(x!=0) isok=false;
    v[x]++;
  }
  if(v[0] != 1 || !isok){
    cout<<0<<endl;
    return 0;
  }

  bool ok=true;
  rep(i,1,N){
    if(v[i-1]==0 && v[i]>0) ok=false;
  }
  if(!ok){
    cout<<0<<endl;
    return 0;
  }
  ll ans = 1;
  for(int i=1; i<N ; i++){
    if(v[i]==0) break;
    ans *= jow(v[i], v[i-1]);
    ans %= mo;
  }
  cout << ans << endl;
  return 0;
}
