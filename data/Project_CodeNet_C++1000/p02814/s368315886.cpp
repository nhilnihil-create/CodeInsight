#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

int gcd(int a, int b) {
  if (a < b) {
    int tmp = a;
    a = b;
    b = tmp;
  }

  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int lcm(int a, int b) { return b / gcd(a, b) * a; }


void solve() {
  int N, M;
  cin >> N >> M;

  vector<int> A(N);
  int l = 1;
  for (int &a: A) {
    cin >> a;
    a /= 2;
    l = lcm(l, a);
  }

  for (int a:A) {
    if ((l / a) % 2 == 0) {
      cout << 0 << endl;
      return;
    }
  }

  int ans = 0;
  for (int x = l; x <= M; x += l + l) {
    ans++;
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
