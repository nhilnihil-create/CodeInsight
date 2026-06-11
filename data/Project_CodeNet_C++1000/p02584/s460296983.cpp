/****Author: ABHIMANYU****/
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
using i128 = __int128_t;
void solve(){
	ll x, k, d; cin >> x >> k >> d;
  i128 X = abs(x);
  while (k) {
    ll k2 = (k + 1) / 2;
    X = abs(X - i128(k2) * d);
    k /= 2;
  }
  cout << ll(X) << endl;

}


int main(){
/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}