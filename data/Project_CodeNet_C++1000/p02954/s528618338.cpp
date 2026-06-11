#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		string S;
		cin >> S;

		int N = (int)S.size();
		vector<int> a( N );

		for( int i = 0; i < N-1; ++i ) {
			if( S[i] != 'R' || S[i+1] != 'L' ) { continue; }

			for( int j = i; j >= 0 && S[j] == 'R'; --j ) {
				if( (i-j)%2 == 0 ) { a[i] += 1; }
				else { a[i+1] += 1; }
			}

			for( int j = i+1; j < N && S[j] == 'L'; ++j ) {
				if( (j-i)%2 == 0 ) { a[i] += 1; }
				else { a[i+1] += 1; }
			}
		}

		for( int i = 0; i < N; ++i ) {
			cout << a[i] << "\n "[i < N-1];
		}
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
