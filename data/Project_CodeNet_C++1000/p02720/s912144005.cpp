#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int cnt = -1;

ll hoge(ll n, ll c, ll k) {
  if (n == 0)
    return ++cnt == k ? c : 0;

  ll ret = 0;
  if (c == 0) {
    for (int i = 0; i < 10; ++i)
      ret += hoge(n - 1, c * 10 + i, k);
  }
  else {
    ll tmp = c % 10;
    if (0 < tmp)
      ret += hoge(n - 1, c * 10 + tmp - 1, k);
    ret += hoge(n - 1, c * 10 + tmp, k);
    if (tmp < 9)
      ret += hoge(n - 1, c * 10 + tmp + 1, k);
  }
  return ret;
}

int main() {
  ll k;
  cin >> k;
  cout << hoge(10, 0, k) << endl;
}