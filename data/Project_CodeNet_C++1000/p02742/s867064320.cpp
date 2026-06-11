#include "bits/stdc++.h"
using namespace std;

int main() {
	long long H, W;
	cin >> H >> W;
	if ((1 == H) || (1 == W)) {
		cout << 1 <<endl;
		return 0;
	}
	long long S = H * W;
	cout << (S + 1) / 2 << endl;
	return 0;
}