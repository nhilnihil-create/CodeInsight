#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3010;
const int mod = 998244353;
int n, s;
ll arr[N], dp[N][N];
bool vis[N][N];

ll fun(int pos, int rem) {
  if (pos > n) {
    if (rem == 0) return 1;
    return 0;
  }
  ll &ret = dp[pos][rem];
  if (vis[pos][rem]) return ret;
  vis[pos][rem] = true;
  ret = 0;
  if (rem >= arr[pos]) {
    ret = (ret + fun(pos + 1, rem - arr[pos])) % mod;
  }
  ret = (ret + 2LL*fun(pos + 1, rem)) % mod;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  cout << fun(1, s) << '\n';
}