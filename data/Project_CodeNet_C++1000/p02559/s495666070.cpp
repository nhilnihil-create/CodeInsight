#include <atcoder/fenwicktree>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  atcoder::fenwick_tree<int64_t> ft(N);
  rep(i, N) {
    int64_t a;
    cin >> a;
    ft.add(i, a);
  }

  rep(i, Q) {
    int t;
    cin >> t;
    if (t == 0) {
      int p;
      int64_t x;
      cin >> p >> x;
      ft.add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << ft.sum(l, r) << endl;
    }
  }
  return 0;
}
