#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	bool can = true;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a % 2 != 0) continue;
		if (a % 3 != 0 && a % 5 != 0) can = false;
	}
	if (can) cout << "APPROVED" << endl;
	else cout << "DENIED" << endl;
    return 0;
}