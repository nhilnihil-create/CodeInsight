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
  int n, i, x, d, c = 1, s = 0;
  cin >> n >> x;
  int a[n], b[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    s = s + a[i];
    if (s <= x) c++;
  }
  cout << c << endl;
}