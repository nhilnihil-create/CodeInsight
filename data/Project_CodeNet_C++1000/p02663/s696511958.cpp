#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int h1, m1, h2, m2, k; cin >> h1 >> m1 >> h2 >> m2 >> k;
	int sum = 0;
	if (h2 < h1) {
		h2 += 24;
	}		
	sum += (60 * h2 + m2) - (60 * h1 + m1) - k;
	cout << sum << endl;
	return 0;
}