#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll h, cnt = 0, ans;
  cin >> h;

  cnt = floor(log2(h));
  ans = (ll)pow(2, cnt + 1) - 1;

  cout << ans << endl;
  return 0;
}
