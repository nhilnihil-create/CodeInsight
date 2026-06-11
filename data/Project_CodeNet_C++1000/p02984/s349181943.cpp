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

	vector<long long> ans( N );
	ans[0] = A[N - 1] + A[0];
	int j = 1;
	for( int i = 0; i < N - 2; i++ ) {
		if( i % 2 ) ans[0] += A[j];
		else ans[0] -= A[j];
		j++;
	}
	for( int i = 1; i < N; i++ ) {
		ans[i] = A[i - 1] * 2 - ans[i - 1];
	}

	for( int i = 0; i < N; i++ ) {
		if( i ) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
