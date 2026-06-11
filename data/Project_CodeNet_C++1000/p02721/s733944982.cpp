#include <iostream>
using namespace std;

int main() {
	int n, k, c;
	cin >> n >> k >> c;
	string s;
	cin >> s;
	int L[n], R[n];
	fill(L, L+n, 0);
	fill(R, R+n, 0);
	for (int i = 0, x = 1; x <= k; i++) {
		if (s[i] == 'x') continue;
		L[i] = x;
		x++;
		i += c;
	}
	for (int i = n-1, x = k; x >= 1; i--) {
		if (s[i] == 'x') continue;
		R[i] = x;
		x--;
		i -= c;
	}
	for (int i = 0; i < n; i++) {
		if (L[i] != 0 && L[i] == R[i]) cout << i+1 << endl;
	}
	return 0;
}