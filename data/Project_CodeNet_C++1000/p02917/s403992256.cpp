// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  --n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  vector<int> a(n + 1, INT_MAX);
  for (int i = 0; i < n; ++i) {
    a[i] = min(a[i], b[i]);
    a[i + 1] = min(a[i + 1], b[i]);
  }
  cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
}