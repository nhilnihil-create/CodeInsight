#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int m1 = a[0], m2 = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] > m1) {
      m2 = m1;
      m1 = a[i];
    } else if (a[i] > m2) {
      m2 = a[i];
    }
  }
  
  rep(i, n) {
    if (a[i] == m1) cout << m2 << endl;
    else cout << m1 << endl;
  }
  return 0;
}