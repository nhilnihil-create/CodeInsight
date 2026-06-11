#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> A( N );
	vector<long long> B( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i] >> B[i];
	}

	sort( A.begin(), A.end() );
	sort( B.begin(), B.end() );
	long long ans;
	if( N % 2 ) {
		long long am = A[N / 2];
		long long bm = B[N / 2];
		ans = bm - am + 1;
	}
	else {
		double am = (double)(A[N / 2 - 1] + A[N / 2]) / 2;
		double bm = (double)(B[N / 2 - 1] + B[N / 2]) / 2;
		ans = (bm - am) * 2 + 1;
	}

	cout << ans << endl;
}
