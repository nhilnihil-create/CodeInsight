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

ll calc_div1(ll n, ll p) {
  if (n == 0) return 0;
  return n / p + calc_div1(n / p, p);
}

ll calc_div2(ll n, ll p) {
  if (n % 2 == 1) {
    return calc_div1(n, p) - calc_div2(n - 1, p);
  }
  ll res = calc_div1(n / 2, p);
  if (p == 2) res += n / 2;
  return res;
}

int main() {
  ll N;
  cin >> N;
  ll ans = min(calc_div2(N, 2), calc_div2(N, 5));
  cout << ans << endl;
  return 0;
}