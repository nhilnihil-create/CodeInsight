#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
using namespace std;

const int N = 3010;
vector<int> v, t;
long long memo[N][N];
long long mod = 1e9 + 7;

inline long long add_mod(long long a, long long b) {
  long long res = a + b;
  if(res > mod) res -= mod;
  if(res < 0) res += mod;
  return res % mod;
}

long long count_dp(int i, int j) {
  if(i == v.size() || j == t.size()) {
    return 1;
  }
  if(memo[i][j] != -1) return memo[i][j];
  long long ans = add_mod(add_mod(count_dp(i + 1, j), 
    count_dp(i, j + 1)), -count_dp(i + 1, j + 1));
  if(v[i] == t[j]) {
    ans = add_mod(ans, count_dp(i + 1, j + 1));
  }
  return memo[i][j] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    int x; cin >> x;
    v.push_back(x);
  }

  for(int i = 0; i < m; ++i) {
    int x; cin >> x;
    t.push_back(x);
  }
  memset(memo, -1, sizeof memo);
  cout << count_dp(0, 0)<< endl;
}
