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
  ll X, A;
  cin >> X >> A;
  int ans = (X < A) ? 0 : 10;
  cout << ans << endl;
  return 0;
}