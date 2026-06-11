

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;



int main() {
	int n, m, q;
	cin >> n >> m >> q;


	vector<vector<int>> con(q, vector<int>(4));
	for (int i = 0; i < q; i++) {
		
		cin >> con[i][0]>> con[i][1] >> con[i][2] >> con[i][3];
		con[i][0]--;
		con[i][1]--;
	}

	int ans = 0;
	for (int bi = 0; bi <= (1 << n + m - 1); bi++) {

		int cnt = 0;
		for (int i = 0; i < n + m - 1; i++) {
			if (((bi >> i) & 1) == 1) {
				cnt++;
			}
		}

		if (cnt != m - 1) {
			continue;
		}

		vector<int> seq;
		int num = 1;
		for (int i = 0; i < n + m - 1; i++) {
			if (((bi >> i) & 1) == 1) {
				num++;
			}
			else {
				seq.emplace_back(num);
			}
		}

		int score = 0;
		for (int i = 0; i < q; i++) {
			if (seq[con[i][1]] - seq[con[i][0]] == con[i][2]) {
				score += con[i][3];
			}
		}

		ans = max(ans, score);
	}

	cout << ans;
}