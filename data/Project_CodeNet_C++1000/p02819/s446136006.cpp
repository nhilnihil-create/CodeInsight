#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MAX = 1000010;

vector<bool> prime_table(int n) {
  vector<bool> res(n + 1, true);
  res[0] = false;
  if (n >= 1) res[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (!res[i]) continue;
    for (int j = i + i; j <= n; j += i)
      res[j] = false;
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin >> x;
  auto p = prime_table(MAX);
  for (int i = x; i < MAX; i++) {
    if (p[i]) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}