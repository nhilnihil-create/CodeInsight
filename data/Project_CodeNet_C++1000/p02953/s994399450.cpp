#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  bool flag = true;
  a[0]--;
  for (int i = 1; i < n; i++) {
    if(a[i] == a[i - 1]) continue;
    else if(a[i] > a[i - 1]) a[i]--;
    else if(a[i] < a[i - 1]) flag = false;
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}