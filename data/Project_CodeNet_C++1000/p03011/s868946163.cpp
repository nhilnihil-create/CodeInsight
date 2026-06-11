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
  ll P, Q, R;
  cin >> P >> Q >> R;
  cout << min({P + Q, Q + R, R + P}) << endl;
  return 0;
}