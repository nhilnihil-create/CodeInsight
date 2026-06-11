#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) % 2 == 0)
    cout << abs(a - b) / 2 << endl;
  else
    cout << min((a + b - 1) / 2, (2 * n - a - b + 1) / 2) << endl;
  return 0;
}