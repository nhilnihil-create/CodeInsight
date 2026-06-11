#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  rep(i,n+1) cin >> a[i];

  int l = a[n];
  ll r[n];
  r[n]=a[n];
  for(int i=n-1; i>=0; i--) {
    l = (l+1)/2;
    l += a[i];
    r[i] = r[i+1]+a[i];
  }
  if(l>1) {
    cout << -1 << endl;
    return 0;
  }

  ll cnt = 1;
  ll ans = 0;
  for(int i=0; i<=n; i++) {
    ans += cnt;
    cnt = min(r[i+1],(cnt-a[i])*2);
  }

  cout << ans << endl;
}
