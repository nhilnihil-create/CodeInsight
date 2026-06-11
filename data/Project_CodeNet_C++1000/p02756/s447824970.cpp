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
  cin.tie(0);ios::sync_with_stdio(false);
  string s, head, tail, tmp;
  head = tail = "";
  int q, cnt = 0;
  cin >> s;
  cin >> q;
  rep (i, q) {
    int x; cin >> x;
    if (x == 1) {
      ++cnt;
      swap(head, tail);
    } else {
      int p; cin >> p;
      cin >> tmp;
      if (p == 1) {
        head += tmp;
      } else {
        tail += tmp;
      }
    }
  }
  if (cnt % 2 != 0) reverse(s.begin(), s.end());
  reverse(head.begin(), head.end());
  cout << head + s + tail << endl;
  return 0;
}
