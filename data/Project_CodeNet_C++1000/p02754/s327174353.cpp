#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n, a, b;
  cin >> n >> a >> b;

  int cycle = a + b;
  int loop = n / cycle;

  int blue = a * loop;
  int left = n - cycle * loop;

  left = min(left, a);
  blue += left;

  cout << blue << '\n';
}

