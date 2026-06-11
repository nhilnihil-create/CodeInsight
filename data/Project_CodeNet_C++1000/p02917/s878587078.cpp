#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> B( N - 1 );
	for( int i = 0; i < N - 1; i++ ) {
		cin >> B[i];
	}

	vector<int> A( N );
	for( int i = 0; i < N; i++ ) {
		if( i == 0 ) A[i] = B[i];
		else if( i == N - 1 ) A[i] = B[N - 2];
		else A[i] = min( B[i], B[i - 1] );
	}
	long long ans = 0;
	for( int i = 0; i < N; i++ ) {
		ans += A[i];
	}

	cout << ans << endl;
}
