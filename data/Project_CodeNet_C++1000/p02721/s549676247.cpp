#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, c;
	string s;

	cin >> n >> k >> c >> s;

	int L[k], R[k];

	int cur = 0;

	memset(L, -1, k);
	memset(R, -1, k);

	for(int i = 0; i < k; i++){
	
		for(; cur < n; cur++){
			if(s[cur] == 'o'){
				L[i] = cur;
				cur += c + 1;
				break;
			}
		}
	
	}
	cur = n-1;
	for(int i = k-1; i >= 0; i--){
	
		for(; cur >= 0; cur--){
			if(s[cur] == 'o'){
				R[i] = cur;
				cur -= c + 1;
				break;
			}
		}
	
	}

	// for(int i = 0; i < k; i++)
	// 	cout << L[i] << ' ' << R[i] << '\n';

	bool e = false;
	for(int i = 0; i < k; i++)
		if(L[i] == R[i] && L[i] != -1){
			e = true;
			cout << L[i] + 1<< '\n';
		}
	if(!e)
		cout << '\n';
	return 0;
}

/*template < typename T >
long long modexp(T a, T b, T p) {
	// returns a to the power b mod p by modular exponentiation

	long long res = 1;
	long long mult = a % p;
	while (b > 0) {
		if (b & 1) {
			res = (res * mult) % p;
		}
		b >>= 1;
		mult = (mult * mult) % p;
	}

	return res;
}*/

/*int primeModInverse(int a, int n) {
	// returns inverse of a mod n by mod exponentiation, use only if n is prime
	return (int) modexp(a, n - 2, n);
}*/

/*template < typename T >
T gcd(T a, T b) {

	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);

}*/
