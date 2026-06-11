#include<bits/stdc++.h>

using namespace std;
#define rep(j,n) for(int j=0;j<(n);j++)

using ll = long long;
using P = pair<int, int>;

int main(int, char**)
{
  int n;
  cin >> n;

  ll ans = (ll)n * (n+1) * (n+2) / 6;

  int u, v;
  rep(i,n-1) {
    cin >> u >> v;
    if (u > v) swap(u,v);
    ans -= (ll)u * (n-v+1);
  }

  cout << ans << endl;

  return 0;
}