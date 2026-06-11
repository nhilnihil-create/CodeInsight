#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <utility>
#include <cassert>
#include <numeric>
#include <random>


using namespace std;
typedef long long ll;

const int MAXN = 1e5+100;
const ll mod = 1e9+7;
int n, m;
set<int> blocked;
ll dp[MAXN];
ll go(int pos) {
  if (pos == n) {
    return 1;
  }
  if (pos > n) return 0;
  if (blocked.count(pos)) return 0;
  if (dp[pos] != -1) return dp[pos];
  ll res = (go(pos+1) + go(pos+2)) % mod;
  return dp[pos] = res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n+1; i++) {
    dp[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    blocked.insert(x);
  }

  ll res = go(0);
  cout << res << endl;
  return 0;
}
