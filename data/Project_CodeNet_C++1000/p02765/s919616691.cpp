#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(0)





void solve() {

	
	int n, r;
	cin >> n >> r;
	if(n >= 10) {
		cout << r << "\n";
	}
	else {
		cout << r + (100 * (10 - n)) << "\n";
	}




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	fix;
	solve();

	return 0;
}