#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,D;
	cin >> N >>D;
	int ans = N / (1 + 2 * D);
	if (0 != N % (1 + 2 * D)) {
		ans++;
	}
	cout << ans <<endl;
	return 0;
}