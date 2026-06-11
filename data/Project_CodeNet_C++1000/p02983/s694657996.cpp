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
  ll l, r;
  cin >> l >> r;
  ll ans = INF;
  vector<ll> a;

  int pl = l;
  while (l <= r && l <= (pl + 2019)) a.push_back(l++); 

  for (int i = 0; i < a.size() - 1; i++) {
    for (int j = i + 1; j < a.size(); j++) {
      ans = min(ans, a[i] * a[j] % 2019);
    }
  }

  cout << ans << endl;

  return 0;
}
