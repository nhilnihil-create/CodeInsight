#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> h(n+1);
  for (int i = 1; i <= n; i++) cin >> h[i];

  vector<bool> t(n+1, true);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (h[a] < h[b]) t[a] = false;
    else if (h[a] > h[b]) t[b] = false;
    else if (h[a] == h[b]) {
      t[a] = false;
      t[b] = false;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (t[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}