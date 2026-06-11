#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
#define vall(x) (x).begin(), (x).end()
using namespace std;
using namespace atcoder;
using lli = long long int;
void YESNO(bool), YesNo(bool);
template <class T1, class T2> bool chmin(T1 &l, const T2 &r);
template <class T1, class T2> bool chmax(T1 &l, const T2 &r);
template <class T1, class T2> void vadd(vector<T1> &v, T2 x);

#define int long long int

signed main() {
  int n, q;

  cin >> n >> q;
  vector<int> a(n);
  fenwick_tree<lli> fen(n);
  rep(i, n) {
    cin >> a[i];
    fen.add(i, a[i]);
  }
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t) {
      cout << fen.sum(a, b) << endl;
    } else {
      fen.add(a, b);
    }
  }

  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2> bool chmin(T1 &l, const T2 &r) {
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2> bool chmax(T1 &l, const T2 &r) {
  return (l < r) ? (l = r, true) : false;
}

template <class T1, class T2> void vadd(vector<T1> &v, T2 x) {
  for (auto &s : v)
    s += T2(x);
}
