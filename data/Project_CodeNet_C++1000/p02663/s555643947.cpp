#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int h1, m1, h2, m2, k;
	cin >> h1 >> m1 >> h2 >> m2 >> k;
	int total_h = h2 - h1, total_m = m2 - m1;
	total_m += (total_h * 60);
	total_m -= k;
	cout << total_m << '\n';
	
	return 0;
}
