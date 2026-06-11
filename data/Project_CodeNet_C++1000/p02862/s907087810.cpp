#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7, N = 2e6 + 1;
int x, y, f[N], inv[N];

int binpow(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) (res *= a) %= mod, --b;
		else (a *= a) %= mod, b >>= 1;
	}
	return res;
}

int inverse(int x){
	return binpow(x, mod - 2);
}

void preset(){
	f[0] = 1, inv[0] = 1;
	for(int i = 1; i < N; ++i) f[i] = (f[i - 1] * i) % mod, inv[i] = inverse(f[i]);
}

signed main(){
	int res = 0;
	cin >> x >> y;
	preset();
	if(x > y) swap(x, y);
	int tx = x, ty = y, cnt = 0;
	while(tx > 0 && ty > 0 && tx != ty) --tx, ty -= 2, ++cnt;
	
	if(tx % 3 == 0 && ty % 3 == 0 && tx == ty){
		int n = 2 * tx / 3 + cnt;
		res = ((f[n] * inv[tx / 3]) % mod) * inv[tx / 3 + cnt] % mod;
	}
	
	cout << res;
}