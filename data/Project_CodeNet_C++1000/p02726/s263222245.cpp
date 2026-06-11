#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, x, y; cin >> n >> x >> y;
	vector<int> num(n, 0);
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			int a = abs(i - j);
			int b = abs(i - x) + 1 + abs(y - j);
			int c = abs(i - y) + 1 + abs(x - j);
			int x = min({ a,b,c });
			if (x < 1 || n - 1 < x) continue;
			num[x]++;
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		cout << num[i] << endl;
	}
	return 0;
}