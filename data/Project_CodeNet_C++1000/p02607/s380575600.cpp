#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int ans = 0;
  rep(i, n) {
    cin >> a[i];
    if ((i+1) % 2 == 1 && a[i] % 2 == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}