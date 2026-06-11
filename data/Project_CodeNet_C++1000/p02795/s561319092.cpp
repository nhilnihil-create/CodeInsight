#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int H, W, N;
	cin >> H >> W >> N;
	int a = max( H, W );
	cout << (N+a-1) / a << endl;

	return 0;
}
