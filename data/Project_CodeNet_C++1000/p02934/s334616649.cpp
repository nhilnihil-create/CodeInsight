#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    double a;
    cin >> a;
    ans += 1 / a;
  }
  cout << fixed << setprecision(10) << 1 / ans << endl;
  return 0;
}