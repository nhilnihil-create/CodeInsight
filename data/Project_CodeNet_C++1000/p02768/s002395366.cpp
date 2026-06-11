#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;
const int N = 200005;

int f[N];

int sub(int x, int y) {
  x -= y;
  if (x < 0) x += md;
  return x;
}

int mul(int x, int y) {
  return (int)((long long)x * y % md);
}

int power(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) {
      ans = mul(ans, x);
    }
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}

int inv(int x) {
  return power(x, md - 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = mul(i, f[i - 1]);
  }
  int n, a, b;
  cin >> n >> a >> b;
  int ans = power(2, n) - 1;
  
  int _min = min(a, n - a);
  int num = 1;
  for (long long i = max(a, n - a) + 1; i <= n; i++) {
    num = mul(num, i);
  }
  int foo = mul(num, inv(f[_min]));
  
  _min = min(b, n - b);
  num = 1;
  for (long long i = max(b, n - b) + 1; i <= n; i++) {
    num = mul(num, i);
  }
  int bar = mul(num, inv(f[_min]));
  
  ans = sub(ans, foo);
  ans = sub(ans, bar);
  cout << ans << '\n';
  return 0;
}