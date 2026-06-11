#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll h1, h2, m1, m2, k, ans = 0;
  cin >> h1 >> m1 >> h2 >> m2 >> k;

  ans = (h2 - h1) * 60 + (m2 - m1) - k;

  cout << ans << endl;
  return 0;
}
