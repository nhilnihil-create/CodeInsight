#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<queue>
#include<iomanip>
#include<bitset>
#include<math.h>
#include<stack>
#include<set>
using namespace std;
#define int long long
int mod = 1000000007;
int bp(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b & 1) {
		return ((a * bp(a, b - 1)) % mod);
	}
	else {
		return (bp((a * a)%mod, b / 2) % mod);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	int n, k;
	cin >> n >> k;
	int r = 0;
	vector<int> v(k+1);
	for (long long i = k; i >= 1; i--) {
		int banana = bp(k / i, n);
		for (long long j = 2; i*j <= k; j++) {
			banana = (banana - v[j * i] + mod)%mod;
		}
		v[i] = banana;
		r += (v[i]*i)%mod;
		r %= mod;
		//cout <<i << ' '<< v[i] << endl;
	}
	cout << r;
}
	