#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int div[n+1];
  ll ans=0;
  for (ll i=1;i<=n;i++) {
    ll d=n/i;
    ans+=i*(d+1)*d/2;
  }
  cout << ans << endl;
}

