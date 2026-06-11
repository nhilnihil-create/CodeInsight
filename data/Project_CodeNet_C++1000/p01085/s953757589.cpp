#include <iostream>

using namespace std;

int main(void) {
	int m, n_min, n_max;
	int score[10001] = { 0 }, gap, ans, tmp;

	while (1) {
		cin >> m; cin >> n_min; cin >> n_max;
		if (m == 0 && n_min == 0 && n_max == 0) break;

		gap = 0;
		ans = 0;
		for (int i = 1; i <= m; i++) {
			cin >> score[i];
		}
		for (int j = n_min; j <= n_max; j++) {
			if ((tmp = score[j] - score[j + 1]) >= gap) {
				gap = tmp;
				ans = j;
			}
		}
		cout << ans <<endl;
	}

	return 0;
}
