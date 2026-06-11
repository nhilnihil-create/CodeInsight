#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <utility>
#include <cassert>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    if (k <= h) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
