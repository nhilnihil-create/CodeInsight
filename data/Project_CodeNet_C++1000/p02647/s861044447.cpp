#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	vector<int> b( N, N );
	vector<int> B( N );
	while( 1 ) {
		for( int i = 0; i < N; i++ ) {
			int l = max( 0, i - A[i] );
			int r = min( N - 1, i + A[i] );
			B[l]++;
			if( r + 1 < N ) B[r + 1]--;
		}
		for( int i = 1; i < N; i++ ) {
			B[i] += B[i - 1];
		}
		K--;
		if( K <= 0 || B == b ) break;
		A = B;
		B = vector<int>( N );
	}

	for( int i = 0; i < N; i++ ) {
		if( i ) cout << " ";
		cout << B[i];
	}
	cout << endl;
}
