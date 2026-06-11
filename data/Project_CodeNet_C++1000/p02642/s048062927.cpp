#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ma = 0;
	vector<int> av(n);
	for (auto& a : av) {
		cin >> a;
		ma = max(a, ma);
	}

	vector<int> cv(ma + 1, 0);
	for (auto& a : av) {
		int b = a;
		while (b <= ma) {
			++cv[b];
			b += a;
		}
	}

	int ret = 0;
	for (auto& a : av) {
		if (cv[a] == 1) {
			++ret;
		}
	}
	cout << ret << endl;

	return 0;
}