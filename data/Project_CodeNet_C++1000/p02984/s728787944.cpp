#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep (i, n) cin >> a[i];

  ll sum = 0, minus = 0;
  rep (i, n) {
    if (i % 2 == 0) {
      sum += a[i];
    } else {
      minus += a[i];
    }
  }

  ll x = (sum - minus);
  x /= 2;
  cout << x * 2 << " ";
  for (int i = 0; i < n - 1; i++) {
    if (a[i] - x == 0) {
      cout << "0" << " ";
      x = 0;
    } else {
      cout << (a[i] - x) * 2 << " ";
      x = (a[i] - x);
    }
  }
  cout << endl;
  return 0;
}
