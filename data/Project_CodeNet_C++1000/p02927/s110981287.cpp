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
  ll M, D;
  cin >> M >> D;
  ll ans = 0;
  for (int i = 1; i <= M; i++) {
    for (int j = 22; j <= D; j++) {
      string d = to_string(j);
      if (d[1] - '0' > 1 && i == (d[0] - '0') * (d[1] - '0')) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}