#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//get the biggest element.
template<typename KeyType, typename ValueType>
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>;
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  });
}
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n, -1);
  rep (i, m) {
    int p, q;
    cin >> p >> q;
    --p;
    if (a[p] != -1 && a[p] != q || p == 0 && q == 0 && n != 1) {
      cout << -1 << endl;
      return 0;
    }
    a[p] = q;
  }

  for (int i = 0; i < n; i++) {
    if (i == 0 && a[i] == -1 && n != 1) {
      a[i] = 1;
    }
    if (a[i] == -1) {
      a[i] = 0;
    }
  }

  for (auto v : a) cout << v;
  cout << endl;
  return 0;
}
