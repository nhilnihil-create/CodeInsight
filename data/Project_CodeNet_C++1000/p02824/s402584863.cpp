#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int n, v, p;
ll m, a[100100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> m >> v >> p;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  int l = p - 1, r = n;
  while (l + 1 < r) {
    int i = (l + r) / 2;
    ll h = (p - 1) * m + (n - i) * m;
    for (int j = p - 1; j < i; j++)
      h += a[i] + m - a[j];
    if (a[i] + m >= a[p - 1] && h >= v * m)
      l = i;
    else
      r = i;
  }
  cout << r << "\n";
}
