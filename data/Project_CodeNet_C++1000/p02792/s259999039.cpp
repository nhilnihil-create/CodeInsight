#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<vector<int>> num(10, vector<int>(10, 0));
	for (int i = 1; i <= n; i++) {
		vector<int> d;
		int tmp_i = i;
		while (0 < tmp_i) {
			d.push_back(tmp_i % 10);
			tmp_i /= 10;
		}
		int a = d[0];
		int b = d[d.size() - 1];
		if (a == 0 || b == 0) continue;
		num[a][b]++;
	}
	int ans = 0;
	for (int a = 1; a <= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			ans += num[a][b] * num[b][a];
		}
	}
	cout << ans << endl;
    return 0;
}