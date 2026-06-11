#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
vec hnum(400000,0),wnum(400000,0),hh[400000];
template< typename Monoid >
struct SegmentTree
{
  using F = function< Monoid(Monoid, Monoid) >;
 
  int sz;
  vector< Monoid > seg;
 
  const F f;
  const Monoid M1;
 
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
 
  void set(int k, const Monoid &x)
  {
    seg[k + sz] = x;
  }
 
  void build()
  {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  void update(int k, const Monoid &x)
  {
    k += sz;
    seg[k] += x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  Monoid query(int a, int b)
  {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
 
  Monoid operator[](const int &k) const
  {
    return seg[k + sz];
  }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll H,W,M;
    cin>>H>>W>>M;
    int h,w;
    rep(i,M) cin>>h>>w,hnum[h]++,wnum[w]++,hh[h].push_back(w);
    ll ans=0;
    SegmentTree< ll > seg(W+1, [](int a, int b){ return max(a, b); }, LLONG_MIN);
    rep1(i,W) seg.set(i,wnum[i]);
    seg.build();
    rep1(i,H){
        ll a=0;
        a+=hnum[i];
        for(auto j:hh[i]){
            seg.update(j,-1);
        }
        ans=max(ans,a+seg.query(1,W+1));
        for(auto j:hh[i]){
            seg.update(j,1);
        }
    }
    cout<<ans;
}