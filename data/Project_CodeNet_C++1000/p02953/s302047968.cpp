#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n;

int main() {
  cin >> n;
  vector<int> h(n);
  rep (i, n) {
    cin >> h[i];
  }
  string ans = "Yes";
  for (int i = n-2; i > 0; i--) {
    if (h[i+1] < h[i]) h[i]--;
    if (h[i+1] < h[i]) ans = "No";
  }
  cout << ans << endl;
  return 0;
}
