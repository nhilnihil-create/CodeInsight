// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long ans = LLONG_MAX;
  long long suf = accumulate(a.begin(), a.end(), 0LL);
  long long pref = 0;
  for (auto el : a) {
    suf -= el;
    pref += el;
    ans = min(ans, abs(pref - suf));
  }
  cout << ans << '\n';
}