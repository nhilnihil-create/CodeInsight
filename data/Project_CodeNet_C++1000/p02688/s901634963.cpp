#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n, k;
  cin >> n >> k;
  vector<bool> s(n+1, false);

  for (int i = 0; i < k; i++) {
    int d;
    cin >> d;
    for (int j = 0; j < d; j++) {
      int a;
      cin >> a;
      s[a] = true;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!s[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}