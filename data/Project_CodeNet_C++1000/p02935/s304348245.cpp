#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(all(v));
  double ans = v[0];
  for (int i = 1; i < n; i++) {
    ans = (ans + v[i]) / 2;
  }
  cout << ans << endl;
  return 0;
}