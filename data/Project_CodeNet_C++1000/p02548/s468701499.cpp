#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  // a * b + c = n

  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (n - i * j > 0)
        ans++;
      else
        break;
    }
  }
  cout << ans << endl;
}