#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int l = 1;
	int r = n;
	if (n % 2 == 1) {
		while (m > 0) {
			cout << l << " " << r << endl;
			
			++l;
			--r;
			--m;
		}

		return 0;
	}

	bool f = false;
	while (m > 0) {
		if (!f && r - l <= n / 2) {
			--r;
			f = true;
		}

		cout << l << " " << r << endl;
		
		++l;
		--r;
		--m;
	}
	
	return 0;
}
