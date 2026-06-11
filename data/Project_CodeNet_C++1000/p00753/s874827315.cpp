#include<iostream>
using namespace std;

int isprime[500000];

void GetPrime(int n) {
	for(int i = 2; i <= n; i++ ) isprime[i] = 1;
	isprime[0] = 0; isprime[1] = 0;
	for(int i = 2; i <= n; i++ ) {
		if ( isprime[i] ) {
			for( int j = i*2; j <= n; j += i ) {
				isprime[j] = 0;
			}
		}
	}
}

int main() {
	int n, i;
	GetPrime(400000);
	while( cin >> n ) {
		if (!n) break;
		int ans = 0;
		for( int i = n+1; i <= 2*n; i++ ) {
			ans += isprime[i];
		}
		cout << ans << endl;
	}
	return 0;
}