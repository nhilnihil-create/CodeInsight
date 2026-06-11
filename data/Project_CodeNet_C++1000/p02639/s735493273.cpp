#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int resp = 0;
	for (int i = 1; i <= 5; i++) {
		int a;
		cin >> a;
		if (a == 0)
			resp = i;
	}
	cout << resp << endl;

	return 0;
}