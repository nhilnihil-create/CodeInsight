#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> a(n,0);
  rep(i,0,n) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = 0;
  rep(i,0,n-k) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
