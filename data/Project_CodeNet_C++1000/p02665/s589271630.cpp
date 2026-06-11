#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> A( N + 1 );
	for( int i = 0; i < N + 1; i++ ) {
		cin >> A[i];
	}

	vector<long long> asum( N + 1 );
	for( int i = N; i >= 0; i-- ) {
		if( i == N ) asum[i] = A[i];
		else asum[i] = asum[i + 1] + A[i];
	}
	long long ans = 0;
	vector<long long> B( N + 1 );
	for( int i = 0; i < N + 1; i++ ) {
		if( i == 0 ) {
			B[i] = 1 - A[i];
			if( B[i] < 0 ) {
				ans = -1;
				break;
			}
			ans += A[i] + B[i];
		}
		else if( i == N ) {
			B[i] = 0;
			if( A[i] + B[i] < B[i - 1] || B[i - 1] * 2 < A[i] + B[i] ) {
				ans = -1;
				break;
			}
			ans += A[i] + B[i];
		}
		else {
			long long l = B[i - 1] - A[i];
			long long h = B[i - 1] * 2 - A[i];
			h = min( h, asum[i + 1] );
			if( h < l || h < 0 ) {
				ans = -1;
				break;
			}
			B[i] = h;
			ans += A[i] + B[i];
		}
	}

	cout << ans << endl;
}
