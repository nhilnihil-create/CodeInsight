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
  ll n;
  cin >> n;
  int m = 1000000;
  ll ans = 1000000000010;
  for (int i = 1; i <= m && i <= n; ++i) {
    if (n %i ==0) {
      ll tmp = i + n/i;
      ans = min(ans, tmp);
    }
  }
  cout << ans - 2 << endl;
  return 0;
}
