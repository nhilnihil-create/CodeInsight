#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int N;
	cin >> N;
	cout << N << ":";
	if( N <= 1 ) {
		cout << " " << N << endl;
		return 0;
	}
	long long int M = sqrtl( N ) + 1;
	for( size_t i = 2; i <= M; i++ ) {
		while( N%i == 0 ) {
			cout << " " << i;
			N /= i;
		}
	}
	if( N != 1 ) {
		cout << " " << N;
	}
	cout << endl;
	return 0;
}