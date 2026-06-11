#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;
#define rep(i, n) for(int i = 0; i < int(n); i++)

signed main(){
	int k, x; cin >> k >> x;
	for(int i = max(x - k + 1, -1000000); i <= min(x + k - 1, 1000000); i++){
		cout << i << " ";
	}
	cout << endl;
}