#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll a, b, n;
  cin >> a >> b >> n;

  ll ans = min(n, b - 1);
  cout << a * ans / b - a * (ans / b) << endl;
}
