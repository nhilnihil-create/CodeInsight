#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  for (int i = 0; i < k; i++) {
    vector<int> imos(n);
    for (int j = 0; j < n; j++) {
      int l = max(0, j - a[j]);
      int r = j + a[j] + 1;
      imos[l]++;
      if(r < n) imos[r]--;
    }
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if(j != 0) imos[j] += imos[j - 1];
      if(imos[j] == n) cnt++;
    }

    for (int j = 0; j < n; j++) a[j] = imos[j];

    if(cnt == n) break;
  }

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';

}
