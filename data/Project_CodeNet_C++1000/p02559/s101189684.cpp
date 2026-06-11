#include <iostream>
#include <atcoder/all>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
using namespace atcoder;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
int main()
{
  int n,q; cin >> n >> q;

  fenwick_tree<ll> fw(n);
  rep(i,n) {
    ll a; cin >> a;
    fw.add(i, a);
  }

  rep(i,q) {
    int t; cin >> t;
    if(t == 0) {
      int p, x; cin >> p >> x;
      fw.add(p, x);
    }
    else {
      int l, r; cin >> l >> r;
      cout << fw.sum(l, r) << "\n";
    }
  }
  return 0;
}
