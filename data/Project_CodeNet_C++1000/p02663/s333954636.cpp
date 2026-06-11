#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		int H1, M1, H2, M2, K;
		cin >> H1 >> M1 >> H2 >> M2 >> K;

		int x = 60*H1 + M1;
		int y = 60*H2 + M2;
		cout << y-x-K << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
