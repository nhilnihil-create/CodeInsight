#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

template <typename T>
T gcd(T a, T b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

template <typename T>
set<T> factorize(T num) {
  set<T> result;
  T d = 2;
  while (d * d <= num) {
    if (num % d == 0) {
      num /= d;
      result.insert(d);
    } else {
      d++;
    }
  }
  if (num != 1) result.insert(num);
  return result;
}

int main() {
  ll a, b;
  cin >> a >> b;

  ll cd = gcd(a, b);

  auto s = factorize(cd);

  ll ans = s.size() + 1;
  cout << ans << endl;
}
