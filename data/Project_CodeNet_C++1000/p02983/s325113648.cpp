#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll L, R;
  cin >> L >> R;
  if (R - L >= 2019) {
    cout << 0 << endl;
    return 0;
  }
  int l = L % 2019, r = R % 2019;
  if (l >= r) {
    cout << 0 << endl;
    return 0;
  }
  int ans = 2019;
  for (int i = l; i <= r; ++i) {
    for (int j = i+1; j <= r; ++j) {
      int temp = (i * j) % 2019;
      ans = min(ans, temp);
    }
  }
  cout << ans << endl;
  return 0;
}