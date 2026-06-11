
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  double a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  if (abs(a - b) / (v - w) <= t && v > w)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}