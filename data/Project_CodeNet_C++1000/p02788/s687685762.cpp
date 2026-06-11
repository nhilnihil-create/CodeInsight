#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) (a)=max(a, b)
#define chmin(a, b) (a)=min(a, b)
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;


/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/

class LazySegTree {
public:
  ll n, height;
  vector<ll> data, lazy;
  
  LazySegTree(ll _n) {
    n=1;
    height=1;
    while(n<_n) {
      n*=2;
      height++;
    }
    data=vector<ll>(2*n-1);
    lazy=vector<ll>(2*n-1);
  }
  
  void eval(ll k, ll l, ll r) {
    if(lazy[k]!=0) {
      data[k]+=lazy[k];
      
      if(r-l>1) {
        lazy[k*2+1]+=lazy[k]/2;
        lazy[k*2+2]+=lazy[k]/2;
      }
      lazy[k]=0;
    }
  }
  
  void _add(ll a, ll b, ll x, ll k, ll l, ll r) {
    eval(k, l, r);
    if(r<=a || b<=l) return;
    
    if(a<=l && r<=b) {
      lazy[k]+=(r-l)*x;
      eval(k, l, r);
    }else {
      _add(a, b, x, k*2+1, l, (l+r)/2);
      _add(a, b, x, k*2+2, (l+r)/2, r);
      data[k]=data[k*2+1]+data[k*2+2];
    }
  }
  
  void add(ll a, ll b, ll x) {_add(a, b, x, 0, 0, n);}
  
  //[a, b):要求区間，[l, r):今見ている区間
  ll _sum(ll a, ll b, ll k, ll l, ll r) {
    if(r<=a || b<=l) return 0;
    
    eval(k, l, r);
    if(a<=l && r<=b) {
      return data[k];
    }else {
      ll s=_sum(a, b, k*2+1, l, (l+r)/2);
      ll t=_sum(a, b, k*2+2, (l+r)/2, r);
      return s+t;
    }
  }
  
  ll sum(ll a, ll b) {return _sum(a, b, 0, 0, n);}
  
};



int main() {
  ll i, j, k;
  
  ll N, D, A;
  cin >> N >> D >> A;
  pll p[MAX*2];
  
  
  for(i=0; i<N; i++) {
    cin >> p[i].ft >> p[i].sc;
    p[i].sc=(p[i].sc+A-1)/A;
  }
  p[N]=pll(INF, INF);
  sort(p, p+N);
  
  LazySegTree lst=LazySegTree(N);
  
  ll ans=0;
  for(ll l=0; l<N; l++) {
    ll r=upper_bound(p, p+N+1, pll(p[l].ft+D*2, INF))-p; r--;
    
    ll t=max(0LL, p[l].sc-lst.sum(l, l+1));
    lst.add(l, r+1, t);
    ans+=t;
  }
  
  pt(ans);
  
  
}


