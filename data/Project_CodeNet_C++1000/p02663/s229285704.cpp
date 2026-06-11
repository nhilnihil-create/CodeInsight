#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int h1, m1, h2, m2; cin >> h1 >> m1 >> h2 >> m2;
	int k; cin >> k;
	cout << (h2 * 60 + m2 - h1 * 60 - m1 - k) << endl;
	return 0;
}
