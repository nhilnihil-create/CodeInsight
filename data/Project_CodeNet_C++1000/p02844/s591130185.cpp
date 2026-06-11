#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string s;
  ll n;
  cin >> n >> s;
  ll ans = 0;
  for (int i = 0; i < 1000; i++) {
    char d[3] = {'0' + i / 100, '0' + ((i / 10) % 10), '0' + (i % 10)};
    int cur = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == d[cur]) cur++;
      if (cur == 3) break;
    }
    if (cur == 3) ans++;
  }
  cout << ans << endl;
  return 0;
}