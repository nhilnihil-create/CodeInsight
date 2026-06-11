#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> a( N );
	for( int i = 0; i < N; i++ )  {
		cin >> a[i];
	}

	int ans = 0;
	int n = 1;
	for( int i = 0; i < N; i++ ) {
		if( a[i] != n ) ans++;
		else n++;
	}

	if( ans >= N ) ans = -1;
	cout << ans << endl;
}
