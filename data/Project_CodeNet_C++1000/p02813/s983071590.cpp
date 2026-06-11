#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>p(n), q(n);
	for (auto&& x : p)cin >> x;
	for (auto&& x : q)cin >> x;

	vector<int>g; for (int i = 0; i < n; i++)g.push_back(i + 1);
	vector<vector<int>>np;
	do {
		np.push_back(g);
	} while (next_permutation(g.begin(), g.end()));

	int a, b;
	for (int i = 0; i < np.size(); i++) {
		bool af = true, bf = true;
		for (int j = 0; j < n; j++) {
			if (af)if (np[i][j] != p[j])af = false;
			if (bf)if (np[i][j] != q[j])bf = false;
		}
		if (af)a = i; if (bf)b = i;
	}
	cout << abs(a - b) << endl;

	return 0;
}