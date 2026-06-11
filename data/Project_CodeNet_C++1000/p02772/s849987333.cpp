#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	bool ans = true;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a % 2 == 0 && !(a % 3 == 0 || a % 5 == 0))
			ans = false;
	}
	if (ans)
		cout << "APPROVED" << endl;
	else
		cout << "DENIED" << endl;

	return 0;
}