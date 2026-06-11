#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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

  fenwick_tree<ll> fw(N);
  rep(i,N) {
    int a;
    cin >> a;
    fw.add(i, a);
  }
  rep(qi,Q) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 0) {
      fw.add(x, y);
    } else {
      cout << fw.sum(x, y) << endl;
    }
  }

  return 0;
}