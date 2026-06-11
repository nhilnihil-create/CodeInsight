#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  ll n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ll g = n / i;
    ans += i*g*(g+1)/2;
  }
  cout << ans << endl;
}