#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> groups(n);
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		groups[t - 1]++;
	}

	sort(groups.begin(), groups.end());

	vector<int> sums(n + 1);
	for (int i = 0; i < n; i++) {
		sums[i + 1] = sums[i] + groups[i];
	}

	int times = n;
	int i = n;
	for (int k = 1; k <= n; ++k) {
		while (times > 0) {
			while (i > 0 && groups[i - 1] >= times) {
				i--;
			}

			if (times * (n - i) + sums[i] >= k * times) {
				break;
			}

			times--;
		}

		cout << times << endl;
	}

	return 0;
}
