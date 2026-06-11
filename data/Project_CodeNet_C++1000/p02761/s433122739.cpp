 #include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> s( M );
	vector<int> c( M );
	for( int i = 0; i < M; i++ ) {
		cin >> s[i] >> c[i];
		s[i]--;
	}

	vector<int> ans( N, -1 );
	int flag = 0;
	for( int i = 0; i < M; i++ ) {
		if( ans[ s[i] ] >= 0 && ans[ s[i] ] != c[i] ) {
			cout << -1 << endl;
			return 0;
		}
		ans[ s[i] ] = c[i];
		if( s[i] == 0 && c[i] == 0 ) flag = 1;
	}
	for( int i = 0; i < N; i++ ) {
		if( ans[i] < 0 ) ans[i] = 0;
	}
	if( N > 1 && ans[0] == 0 ) {
		if( flag ) {
			cout << -1 << endl;
			return 0;
		}
		else ans[0] = 1;
	}

	for( int i = 0; i < N; i++ ) {
		cout << ans[i];
	}
	cout << endl;
}
