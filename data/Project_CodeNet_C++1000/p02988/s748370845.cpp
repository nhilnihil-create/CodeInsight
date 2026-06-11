#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin >> a[i];
  }
  int ans = 0;
  for (int i=1; i<n-1; i++) {
    if (a[i] > a[i-1] && a[i] < a[i+1]) ans++;
    else if (a[i] < a[i-1] && a[i] > a[i+1]) ans++;
  }
  cout << ans << '\n';
  return 0;
}
