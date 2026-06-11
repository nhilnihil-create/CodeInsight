#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
vector<ll> memo;
int main() {
  int n;
  cin >> n;
  memo.resize(n + 40, 0);

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      memo[j]++;
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (ll)i * memo[i];
  }

  cout << ans << endl;
}