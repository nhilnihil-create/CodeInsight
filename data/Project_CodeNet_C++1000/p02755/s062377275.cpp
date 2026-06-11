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
  int a, b;
  cin >> a >> b;

  double x1 = ceil(a / 0.08);
  double x2 = ceil(b / 0.1);

  double ans = -1;
  if (floor(0.1 * x1) == b) {
    ans = x1;
  }
  if (floor(0.08 * x2) == a) {
    if (ans == -1) ans = x2;
    else ans = min(ans, x2);
  }

  cout << ans << endl;
  return 0;
}
