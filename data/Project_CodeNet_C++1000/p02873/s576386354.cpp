#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int N = S.size() + 1;
	vector<int> l( N );
	int n = 0;
	for( int i = 0; i < N - 1; i++ ) {
		if( S[i] == '<' ) n++;
		else n = 0;
		l[i + 1] = n;
	}
	vector<int> r( N );
	n = 0;
	for( int i = N - 2; i >= 0; i-- ) {
		if( S[i] == '>' ) n++;
		else n = 0;
		r[i] = n;
	}
	long long ans = 0;
	for( int i = 0; i < N; i++ ) {
		ans += max( l[i], r[i] );
	}

	cout << ans << endl;
}
