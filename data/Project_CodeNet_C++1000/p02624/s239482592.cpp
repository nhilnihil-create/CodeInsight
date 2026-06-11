#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll ans=0;
  int y;
  for (ll i=1;i*i<=n;i++) {
    ll d=n/i;
    ans+=i*(d+1)*d/2;
    y=i;
  }
  int z=n/(y+1);
  for (ll i=1;i<=z;i++) {
      ll low=n/(i+1);
      ll high=n/i;
      ll x=high*(high+1)/2-low*(low+1)/2;
      ans+=x*i*(i+1)/2;
  }
  cout << ans << endl;
}