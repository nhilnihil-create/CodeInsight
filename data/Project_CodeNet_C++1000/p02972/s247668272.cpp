#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<int> b(n + 1), ans;
	for (int i = n; i > 0; i--) {
		if (b[i] % 2 != a[i]) {
			ans.emplace_back(i);
			for (int j = 1; j <= sqrt(i); j++) {
				if (i % j == 0) {
					b[j]++;
					if (i / j != j) {
						b[i / j]++;
					}
				}
			}
		}
	}

	cout << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << (i != 0 ? " " : "\n");
	}

	return 0;
}