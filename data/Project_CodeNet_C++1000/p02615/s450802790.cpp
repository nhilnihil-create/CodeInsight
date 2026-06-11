#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.rbegin(), a.rend());
  int t = n, idx = 0;
  ll ans = 0;
  bool one = true;
  while (t-- > 0) {
    ans += a[idx];
    one ^= 1;
    if (one) ++idx;
  }
  cout << ans-a[0] << endl;
}