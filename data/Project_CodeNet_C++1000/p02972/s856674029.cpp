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

	set<int> ans;
	for( int i = N - 1; i >= 0; i-- ) {
		int n = i + 1;
		int sum = 0;
		for( int j = n + n; j <= N; j += n ) {
			if( ans.count( j ) ) sum++;
		}
		if( a[i] != sum % 2 ) ans.insert( n );
	}

	cout << ans.size() << endl;
	int first = 0;
	for( auto it = ans.begin(); it != ans.end(); it++ ) {
		if( first ) cout << " ";
		cout << *it;
		first = 1;
	}
	if( ans.size() ) cout << endl;

}
