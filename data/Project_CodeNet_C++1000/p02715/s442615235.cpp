#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int MXN = 1e5 + 1;
const int MOD = 1e9 + 7;

int add(int x, int y) {return (x+y) % MOD;}
int mul(int x, int y) {return (x*1ll*y) % MOD;};
int bp(int x, int y) {
	int ans = 1;
	while (y) {
		if (y&1) ans = mul(ans, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> sv[k+1];
	for (int i=1; i<=k; i++) {
		for (int j=2; i*j<=k; j++) {
			sv[i*j].push_back(i);
		}
	}
	vector<int> sub(k+1);
	int ans = 0;
	for (int i=k; i>0; i--) {
		int num = k/i;
		int cur = add(bp(num, n), MOD-sub[i]);
//		cout << i << ' ' << cur << '\n';
		ans = add(ans, mul(i, cur));
		for (int x : sv[i]) {
			sub[x] = add(sub[x], cur);
		}
	}
	cout << ans;
}