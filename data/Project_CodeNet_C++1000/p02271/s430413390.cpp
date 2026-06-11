#include <bits/stdc++.h>
using namespace std;

#define FOR( i, m, n )  for( int (i) = (m); (i) < (n); (i)++ )
#define REP( i, n )     FOR( i, 0, n )
#define ALL( a )        (a).begin(), (a).end()             

int solve( vector<int>& a, int m, int i ) {
	if( m == 0 ) return 1;
	if( i >= a.size() ) return 0;
	int res = solve( a, m, i + 1 ) || solve( a, m - a[i], i + 1 );
}

int main() {
	int n; cin >> n;
	vector<int> a( n );
	REP( i, n ) cin >> a[i];
	
	int q, m; cin >> q;
	REP( i, q ) {
		cin >> m;
		if( solve( a, m, 0 ) ) cout << "yes" << endl;
		else				   cout << "no" << endl;
	}


}
