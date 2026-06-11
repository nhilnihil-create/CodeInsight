#include<bits/stdc++.h>
#define ll long long
#define INF 100000000000000000LL
using namespace std;
signed main() {
  int n, ma = 0, mi = INF;
  ll b, c = INF;
  int a[10000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
    mi = min(mi, a[i]);
  }
  for (int i = mi; i <= ma; i++) {
    b = 0;
    for (int j = 0; j < n; j++) {
      b += (a[j] - i) * (a[j] - i);
    }
    c = min(c, b);
  }
  
  cout << c << "\n";
  return (0);
}