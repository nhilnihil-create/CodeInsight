#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
#define MAX_H 10000
#define MAX_A 10000
//#define DEBUG true
#define DEBUG false
using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

int ceil(int x, int y) { return (x % y == 0) ? x / y : x / y + 1; }

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int lcm(int x, int y) { return x / gcd(x, y) * y; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, n;
  cin >> h >> n;
  vector< int > a(n), b(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    cin >> b[i];
  }

  int dp[MAX_H + MAX_A + 1];
  fill(dp, dp + MAX_H + MAX_A + 1, INF_INT);

  dp[0] = 0;
  for(int i = 1; i <= MAX_H + MAX_A; i++) {
    for(int j = 0; j < n; j++) {
      if(i - a[j] >= 0) {
        dp[i] = min(dp[i], dp[i - a[j]] + b[j]);
      }
    }
  }

  int ans = INF_INT;
  for(int i = h; i <= h + MAX_A; i++) {
    ans = min(ans, dp[i]);
  }

  cout << ans << endl;

  return 0;
}
