#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;
#define rep(i, n) for(int i = 0; i < int(n); i++)

signed main(){
	int n, d; cin >> n >> d;
	int ans = n / (2 * d + 1);
	if(n % (2 * d + 1) != 0) ans++;
	cout << ans << endl;
}