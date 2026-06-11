#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long powmod(long long a, long long b){
	long long c = 1;
	while(b > 0){
		if(b & 1){
			c = a * c % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<long long> d(k + 1);
	for(int i = 1; i < k + 1; i++){
		d[i] = powmod(k / i, n);
	}
	for(int i = k; i >= 1; i--){
		for(int j = 2 * i; j < k + 1; j += i){
			d[i] -= d[j];
			d[i] = (d[i] + mod) % mod;
		}
	}
	long long ans = 0;
	for(int i = 0; i < k + 1; i++){
		ans += d[i] * i;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
