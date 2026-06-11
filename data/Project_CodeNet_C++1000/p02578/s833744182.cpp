#include<bits/stdc++.h>
using namespace std; 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >>x;
  long long ans = 0;
  int mx = 0;
  for (int i = 0 ; i < n; i++) {
    if (a[i] < mx) ans += mx - a[i];
    mx = max(a[i], mx);
  }
  cout << ans;
}