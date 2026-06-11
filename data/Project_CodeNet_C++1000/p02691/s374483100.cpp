#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	vector<long long> add( N );
	for( int i = 0; i < N; i++ ) {
		add[i] = A[i] + i + 1;
	}
	sort( add.begin(), add.end() );
	long long ans = 0;
	for( int i = 0; i < N; i++ ) {
		long long a = i + 1 - A[i];
		ans += upper_bound( add.begin(), add.end(), a ) - lower_bound( add.begin(), add.end(), a );
	}

	cout << ans << endl;
}
