#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long N;
  std::cin >> N;
  long long Q;
  std::cin >> Q;

  atcoder::dsu uf(N);

  for(;Q-->0;) {
    ll q, u, v;
    cin >> q >> u >> v;
    if (q) {
      cout << uf.same(u, v) << endl;
    } else {
      uf.merge(u, v);
    }
  }
  return 0;
}
