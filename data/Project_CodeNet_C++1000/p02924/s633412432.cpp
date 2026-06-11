#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll ans=0;
  rep(i,n) ans+=i;
  cout << ans << endl;
}
