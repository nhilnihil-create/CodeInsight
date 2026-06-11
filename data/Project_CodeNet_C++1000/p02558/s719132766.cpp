#include <bits/stdc++.h>
#include <atcoder/dsu>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;
using namespace atcoder;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  int N, Q;
  cin >> N >> Q;

  dsu d(N);
  rep(qi,Q) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      d.merge(u, v);
    } else {
      cout << (d.same(u, v) ? 1 : 0) << endl;
    }
  }

  return 0;
}