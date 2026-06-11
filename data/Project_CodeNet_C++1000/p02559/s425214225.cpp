#include <iostream>
#include <atcoder/fenwicktree>

using namespace std;

int main() {
  int N, Q, a;
  cin >> N >> Q;
  atcoder::fenwick_tree<long long> f(N);
  for (int i = 0; i != N; ++i) {
    cin >> a;
    f.add(i,a);
  }

  int t,l,r;
  while (cin >> t >> l >> r) {
    if (t) cout << f.sum(l,r) << endl;
    else f.add(l,r);
  }
}
