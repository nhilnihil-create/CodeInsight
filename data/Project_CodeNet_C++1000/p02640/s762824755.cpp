#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> x >> y;
	
	bool resp = false;
	for (int i = 0; i <= x; i++) {
		int count = i * 4 + (x - i) * 2;
		if (count == y)
			resp = true;
	}
	if (resp)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}