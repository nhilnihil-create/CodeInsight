#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (j > i + 1) cout << ' ';
			int b = 0;
			for (int k = 0; k < 15; ++k) {
				if (((i ^ j) >> k) & 1) b = k + 1;
			}
			cout << b;
		}
		cout << '\n';
	}
	return 0;
}