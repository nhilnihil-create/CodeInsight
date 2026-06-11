#include <atcoder/all>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  int n, q;
  cin >> n >> q;
  atcoder::dsu d(n);
  rep(i, q) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) d.merge(u, v);
    if (t == 1) cout << d.same(u, v) << endl;
  }
  return 0;
}