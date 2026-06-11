#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int N, K;
	cin >> N >> K;

	if( K == 1 ) {
		cout << 0 << endl;
	}
	else {
		cout << N-K << endl;
	}

	return 0;
}
