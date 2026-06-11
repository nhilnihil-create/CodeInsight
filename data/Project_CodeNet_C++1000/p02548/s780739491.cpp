#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e18;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  ll n;
  cin >> n;

  ll ans = 0;
  for (ll a = 1; a < n; a++){
    for (ll b = 1; b < n/a + 1; b++){
      if ((n - a * b) > 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
