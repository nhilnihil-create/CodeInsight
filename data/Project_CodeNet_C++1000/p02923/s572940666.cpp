#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> H( N );
	for( int i = 0; i < N; i++ ) {
		cin >> H[i];
	}

	int ans = 0;
	int len = 0;
	for( int i = 0; i < N - 1; i++ ) {
		if( H[i] < H[i + 1] ) len = 0;
		else len++;
		ans = max( ans, len );
	}

	cout << ans << endl;
}
