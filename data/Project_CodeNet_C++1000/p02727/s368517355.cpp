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

const int INF = 2e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<int> red, green, inv;

  for (int i = 0; i < a; i++) {
    int r;
    cin >> r;
    red.push_back(r);
  }

  for (int i = 0; i < b; i++) {
    int r;
    cin >> r;
    green.push_back(r);
  }

  for (int i = 0; i < c; i++) {
    int r;
    cin >> r;
    inv.push_back(r);
  }

  sort(red.rbegin(), red.rend());
  sort(green.rbegin(), green.rend());
  sort(inv.rbegin(), inv.rend());

  red.erase(red.begin()+x, red.end());
  green.erase(green.begin()+y, green.end());

  ll sum = 0;
  for (int c: inv) {
    int min_r = red.empty() ? INF : red.back();
    int min_g = green.empty() ? INF : green.back();
    if (c <= min(min_r, min_g)) break;
    sum += c;
    if (min_r < min_g) {
      red.pop_back();
    } else {
      green.pop_back();
    }
  }

  for (int c: red) sum += c;
  for (int c: green) sum += c;

  cout << sum << endl;

  return 0;
}