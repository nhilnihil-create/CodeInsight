#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  map<int, int> mp;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int sa = i - a[i];
    ans += mp[sa];
    int wa = a[i] + i;
    mp[wa]++;
  }
  cout << ans << endl;
  return 0;
}