#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

long long modpow(long long a, long long b){
	long long c = 1;
	while(b > 0){
		if(b & 1) c = c * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return c;
}

int main() {
	
	int m,n;
	cin >> m >> n;
	cout << modpow(m,n) << endl;
}

