#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> P( N );
	for( int i = 0; i < N; i++ ) {
		cin >> P[i];
	}

	int ans = 0;
	int mi = N + 1;
	for( int i = 0; i < N; i++ ) {
		mi = min( mi, P[i] );
		if( P[i] <= mi ) ans++;
	}

	cout << ans << endl;
}
