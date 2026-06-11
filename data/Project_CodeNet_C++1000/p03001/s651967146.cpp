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
  int W, H, x, y;
  cin >> W >> H >> x >> y;
  cout << fixed << setprecision(10) << ((double)W * (double)H / 2) << " "
       << ((x + x == W) && (y + y == H)) << endl;
  return 0;
}