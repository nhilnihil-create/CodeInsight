#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

ll n, a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> a >> b;
  if ((b - a) % 2 == 0)
    cout << (b - a) / 2 << "\n";
  else
    cout << min((a + b - 1) / 2, (2 * n - a - b + 1) / 2) << "\n";
}
