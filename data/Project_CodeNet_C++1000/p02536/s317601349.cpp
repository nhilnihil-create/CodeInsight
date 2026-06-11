#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 998244353
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
#define Max(a) (*max_element(ALL(a)))
#define Min(a) (*min_element(ALL(a)))
using namespace std;
struct UF
{
  vector<ll> par;
  vector<ll> sz;
  vector<ll> rank;
  UF(ll n):par(n),sz(n),rank(n){
    for(ll i = 0; i < n; i++){
      par[i] = i;sz[i] = 1;rank[i] = 0;
    }
  }
  ll find(ll x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
  }
  void merge(ll x, ll y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if(rank[x] < rank[y]){
      par[x] = y;
      sz[y] += sz[x];
    }
    else{
      par[y] = x;
      sz[x] += sz[y];
      if(rank[x] == rank[y])rank[x]++;
    }
  }
  bool same(ll x, ll y) { return find(x) == find(y); }
  ll size(ll n){return sz[find(n)];}
};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;cin>>n>>m;
  UF uni(n);
  for(int i=0;i<m;i++){
    ll a,b;cin>>a>>b;
    a--;b--;
    uni.merge(a,b);
  }
  set<ll>se;
  for(int i=0;i<n;i++){
    se.insert(uni.find(i));
  }
  cout<<se.size()-1<<endl;
  return 0;
}