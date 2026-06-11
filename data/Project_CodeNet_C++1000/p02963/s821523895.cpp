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
  ll S;
  cin >> S;
  ll x1, y1, x2 = 1000000000, y2 = 1;
  x1 = (x2 - S % x2) % x2;
  y1 = (S + x1) / x2;
  printf("0 0 1000000000 1 %lld %lld\n", x1, y1);
  return 0;
}