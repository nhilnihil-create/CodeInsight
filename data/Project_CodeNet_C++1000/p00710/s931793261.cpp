#include <bits/stdc++.h>
using namespace std;

#define FOR( i, m, n )  for( int (i) = (m); (i) < (n); (i)++ )
#define REP( i, n )     FOR( i, 0, n )
#define ALL( a )        (a).begin(), (a).end()             

int main() {
	int n, r, p, c;

	while( 1 ) {
		cin >> n >> r; if( n == 0 && r == 0 ) break;
		vector<int> card( n );
		vector<int> tmp( n );
		// if n == 3 -> 3 2 1
		REP( i, n ) card[i] = n - i;

		REP( i, r ) {
			cin >> p >> c;
			tmp = card;
			REP( j, p + c - 1 ) {
				if( j < c ) card[j] = tmp[j + p - 1];
				else		card[j] = tmp[j - c];
			}
		}
		cout << card[0] << endl;
	}

}
