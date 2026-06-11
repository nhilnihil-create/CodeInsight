#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto upd = [] (const vector<int>& v) {
    vector<int> imos((int) v.size() + 2);
    for (int i = 1; i <= (int) v.size(); i++) {
      int l = max(0, i - v[i - 1]);
      int r = min((int) v.size() + 1, i + v[i - 1] + 1);
      imos[l]++;
      imos[r]--;
    }
    for (int i = 1; i < (int) imos.size(); i++) {
      imos[i] += imos[i - 1];
    }
    vector<int> res((int) v.size());
    for (int i = 1; i <= (int) v.size(); i++) {
      res[i - 1] = imos[i];
    }
    return res;
  };
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < min(50, k); i++) {
    a = upd(a);
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
  return 0;
}
