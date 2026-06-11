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
  ll H; cin >> H;
  ll ans = 0;
  ll num_monster = 1;
  while (H > 0) {
    if (H == 1) {
      ans += num_monster;
      H = 0;
    }
    else {
      ans += num_monster;
      H /= 2;
      num_monster *= 2;
    }
  }
  cout << ans << endl;
  return 0;
}