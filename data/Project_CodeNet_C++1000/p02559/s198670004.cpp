#include <atcoder/all>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  atcoder::fenwick_tree<ll> fw(n);
  rep(i, n) fw.add(i, a[i]);
  rep(_, q) {
    int t;
    cin >> t;
    if (t == 0) {
      int p, x;
      cin >> p >> x;
      fw.add(p, x);
    }
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      cout << fw.sum(l, r) << endl;
    }
  }
  return 0;
}