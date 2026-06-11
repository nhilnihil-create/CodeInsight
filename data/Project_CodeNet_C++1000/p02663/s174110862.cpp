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
  ll H1, M1, H2, M2, K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  ll res_h = H2 - H1;
  ll res_m = M2 - M1;
  if (res_m < 0) res_h--, res_m = M2 + 60 - M1;
  ll max_m = res_h * 60 + res_m;
  cout << max(max_m - K, 0LL) << endl;
  return 0;
}