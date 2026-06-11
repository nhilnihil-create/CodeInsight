#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string S;
	cin >> S;

	int N = S.size();
	vector<int> l2r( N );
	int cnt = 0;
	for( int i = 0; i < N; i++ ) {
		if( S[i] == 'R' ) cnt = 0;
		else l2r[i] = cnt;
		cnt++;
	}
	vector<int> r2l( N );
	cnt = 0;
	for( int i = N - 1; i >= 0; i-- ) {
		if( S[i] == 'L' ) cnt = 0;
		else r2l[i] = cnt;
		cnt++;
	}
	vector<int> ans( N );
	for( int i = 0; i < N; i++ ) {
		if( S[i] == 'L' ) {
			int idx = i - l2r[i];
			if( l2r[i] % 2 ) idx++;
			ans[idx]++;
		}
		else {
			int idx = i + r2l[i];
			if( r2l[i] % 2 ) idx--;
			ans[idx]++;
		}
	}

	for( int i = 0; i < N; i++ ) {
		if( i ) cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
