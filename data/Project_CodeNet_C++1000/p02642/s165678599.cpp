#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  vector<int> v(*max_element(a.begin(),a.end()) + 1, 0);
  v[0] = 2;

  for (int x : a) {
    if (v[x] != 0) {
      v[x] = 2;
      continue;
    }
    for (int i = x; i <= v.size(); i += x) v[i]++;
  }
  int ans = 0;
  for (int x : a) {
    if(v[x] == 1) ans++;
  }
  cout << ans << endl;

}