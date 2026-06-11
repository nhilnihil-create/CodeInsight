#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	long long K;
	cin >> N >> K;
	vector<long long> A( N );
	for( int i = 0; i < N; i++ )  {
		cin >> A[i];
	}

	const long long MOD = 1000000000 + 7;
	long long ans1 = 0;
	for( int i = 0; i < N; i++ ) {
		for( int j = i + 1; j < N; j++ ) {
			if( A[i] > A[j] ) ans1++;
		}
	}
	long long ans2 = 0;
	for( int i = 0; i < N; i++ ) {
		for( int j = 0; j < N; j++ ) {
			if( A[i] > A[j] ) ans2++;
		}
	}
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
	long long ans = ans1 * K % MOD + ans2 * K % MOD * (K - 1) % MOD * power( 2, MOD - 2 );
	ans %= MOD;

	cout << ans << endl;
}
