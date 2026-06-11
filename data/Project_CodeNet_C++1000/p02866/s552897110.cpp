#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
static const ll MOD = 998244353;

ll _pow_(ll a, ll n, ll m) {
	ll ret = 1;
	for (; n > 0; n >>= 1, a = a * a % m) {
		if (n % 2 == 1) {
			ret = ret * a % m;
		}
	}
	return ret;
}

int main() {
  int n;
  cin >> n;
  vector<ll> d(n, 0);
  rep(i, n){
    int tmp;
    cin >> tmp;
    d[tmp]++;
    if(i == 0 && tmp != 0){
      cout << 0 << endl;
      return 0;
    }
  }
  
  if(d[0] != 1){
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1;
  for(int i = 1; i < n; ++i){
    ans *= _pow_(d[i-1], d[i], MOD);
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
