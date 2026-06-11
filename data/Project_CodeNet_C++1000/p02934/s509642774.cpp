#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int n;
	cin >> n;
	double sum = 0;
	while(n--) {
		int x;
		cin >> x;
		sum += 1 / (double)x;
	}
	cout << fixed;
	setprecision(10);
	cout << 1 / (double)sum << "\n";

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}