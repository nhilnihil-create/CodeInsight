#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

constexpr ll INF = (1LL << 60);

template <typename T> 
struct LazySegmentTree {
  
  int n;
  vector<T> node, lazy;

  LazySegmentTree (int sz, T init = 0) {
    n = 1; while (n < sz) n <<= 1;
    node.assign(2*n, init);
    lazy.assign(2*n, 0); /*区間加算の時は0*/
  }

  void eval (int k) {
    if (lazy[k] == 0) return ;
    node[k] += lazy[k]; /*区間加算に注意*/
    if (k < n) {
      lazy[2*k+1] += lazy[k];
      lazy[2*k+2] += lazy[k];
    }
    lazy[k] = 0;
  }

  void update(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
    eval(k);
    if (r < 0) r = n;
    if (b <= l || r <= a) return ;
    if (a <= l && r <= b) {
      lazy[k] = x;
      eval(k);
    } else {
      update(a, b, x, 2*k+1, l, (r+l)/2);
      update(a, b, x, 2*k+2, (r+l)/2, r);
      node[k] = node[2*k+1] + node[2*k+2];
    }
  }

  T query(int a, int b, int k = 0, int l = 0, int r = -1) {
    eval(k);
    if (r < 0) r = n;
    if (r <= a || b <= l) return 0;
    if (a <= l && r <= b) return node[k];
    T vl = query(a, b, 2*k+1, l, (l+r)/2);
    T vr = query(a, b, 2*k+2, (l+r)/2, r);
    return vl + vr;
  }

};

int main(){
  int n, d, a;
  cin >> n >> d >> a;
  vector<pair<ll, ll>> p(n);
  rep(i,n) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());
  LazySegmentTree<ll> seg(n);
  for (int i = 0; i < n; i++) seg.update(i, i + 1, p[i].second);

  ll res = 0;

  for (int l = 0; l < n; l++) {
    ll h = seg.query(l, l + 1);
    if (h <= 0) continue;
    ll x  = p[l].first + 2 * d;
    auto r = lower_bound(p.begin(), p.end(), make_pair(x, INF)) - p.begin();
    ll cnt = (h + a - 1) / a;
    res += cnt;
    seg.update(l, r, -cnt * a);   
  } 

  cout << res << endl;
  return 0;
} 