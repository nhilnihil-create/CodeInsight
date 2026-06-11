#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
using namespace std;
vector<int> inv;
const int p = 1e9 + 7;
const int N = 2e5 + 5;
inline int pw(int a, int b) { 
	int ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return ans % p;
}
inline int c(int a, int b) { 
	int ans = 1;
	for (int i = a; i >= a - b + 1; --i)
    	ans = (ans * i) % p;
	for (int i = b; i >= 1; --i)
		ans = ans * inv[i] % p;
	return (ans % p + p) % p;
}
inline void init() { 
    inv.push_back(0), inv.push_back(1);
	for (int i = 2; i <= N; ++i) {
        int k = (p - p / i) * inv[p % i] % p;
        inv.push_back(k);
    }
}
signed main() {
	init();
	int n, a, b; cin >> n >> a >> b;
	int ans = pw(2, n) - 1; ans %= p;
	ans -= (c(n, a) + c(n, b)) % p; ans %= p;
	ans = (ans + p) % p;
	cout << ans << endl;
	return 0;
}