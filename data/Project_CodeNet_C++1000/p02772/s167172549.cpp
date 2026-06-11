#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(0)





void solve() {

	int n;
	cin >> n;
	bool ok = 1;
	while(n--) {
		int x;
		cin >> x;
		if(x % 2 == 0) {
			if(x % 3 != 0 && x % 5 != 0) {
				ok = 0;
			}
		}
	}
	if(ok) {
		cout << "APPROVED\n";

	}
	else {
		cout << "DENIED\n";
	}



	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	fix;
	solve();

	return 0;
}