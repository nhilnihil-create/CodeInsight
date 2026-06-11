#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == cnt) {
      cnt++;
    }
  }
  if (cnt == 0) cout << "-1" << endl;
  else cout << n - cnt << endl;
  return 0;
}