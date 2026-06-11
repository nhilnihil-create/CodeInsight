#include <iostream>

using namespace std;

bool sosuu[10000000];

int main() {
	fill(&sosuu[0], &sosuu[0]+10000000, true);

	sosuu[0] = sosuu[1] = false;

	for (int i = 2; i < 10000000; ++i) {
		for (int j = i*2; j < 10000000; j += i) {
			sosuu[j] = false;
		}
	}

	int n;
	while (cin >> n, n) {
		int ans = 0;
		for (int i = n+1; i <= 2*n; ++i) {
			if (sosuu[i]) ++ans;
		}
		cout << ans << endl;
	}
}