#include <bits/stdc++.h>

#define ll long long
#define MOD (1000000007)

using namespace std;

ll power(ll a, ll b){
  	ll result = 1;
	while(b > 0){
		if(b & 1){
			result *= a;
			result %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
  
  	return result;
}

int main() {
	int N; cin >> N;

	if(N < 2){
		cout << 0;
		return 0;
	}

	ll result = power(10,N);
	result += MOD + MOD;
	result -= power(9,N) * 2;
	result %= MOD;
	result += power(8,N);
	result %= MOD;
	
	cout << result;

	return 0;
}

