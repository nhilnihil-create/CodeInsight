#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> D( N );
	for( int i = 0; i < N; i++ ) {
		cin >> D[i];
	}
 
	vector<int> d( N );
	int ma = 0;
	for( int i = 0; i < N; i++ ) {
		d[ D[i] ]++;
		if( D[i] > ma ) ma = D[i];
	}
	if( d[0] > 1 || D[0] != 0 ) {
		cout << 0 << endl;
		return 0;
	}
	for( int i = 0; i <= ma; i++ ) {
		if( d[i] == 0 ) {
			cout << 0 << endl;
			return 0;
		}
	}
 
	const long long MOD = 998244353;
	auto power = [&]( long long x, long long n )
	{
		long long res = 1;
		while( n > 0 ) {
			if( n % 2 ) res = res * x % MOD;
			x = x * x % MOD;
			n /= 2;
		}
		return res;
	};
	long long ans = 1;
	for( int i = 1; i < ma; i++ ) {
		ans *= power( d[i], d[i + 1] );
		ans %= MOD;
	}
 
	cout << ans << endl;
}
