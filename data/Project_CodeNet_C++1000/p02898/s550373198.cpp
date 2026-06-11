#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;

signed main(){
	int n, k, ans = 0; cin >> n >> k;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x >= k) ans++;
	}
	cout << ans << endl;
}