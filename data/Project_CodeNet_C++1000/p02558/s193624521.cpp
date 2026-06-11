//\\//\\ * * * //\\// ||
#include <bits/stdc++.h> 

#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 10;

class dsu {
 public:
  int p[N];
  int n;

  dsu(int _n) : n(_n) {
    iota(p, p + n, 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  dsu d(n);
  while (tt--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 0) {
      d.unite(a, b);
    } else {
      cout << (d.get(a) == d.get(b)) << '\n';
    }
  }
  return 0;
}
