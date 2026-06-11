#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	static int H[310];
	// 初期状態の必要な回数
	long long initial = 0;
	for(int i = 1; i <= N; i++) {
		cin >> H[i];
		if(H[i - 1] < H[i]) {
			initial += H[i] - H[i - 1];
		}
	}

	// flat[a][b]: a <= i <= bのH[i] = H[b + 1]としたときの減少数
	static long long flat[310][310];
	for(int b = N; b >= 1; b--) {
		for(int a = b; a >= 1; a--) {
			const auto left = H[a - 1];
			const auto right = H[b + 1];
			const auto x = H[a];
			int d = 0;

			// 谷の場合
			if(left > x && x < right) {
				d = min(left, right) - x;
			}
			// 山の場合
			else if(left < x && x > right) {
				d = x - max(left, right);
			}

			flat[a][b] = d + flat[a + 1][b];
		}
	}

	// ans[a][k]: a以降にコストkを使える時の最大減少数
	static long long ans[310][310];
	for(int k = 1; k <= K; k++) {
		for(int a = N; a >= 1; a--) {
			// a始めにコストを使わない
			ans[a][k] = max(ans[a][k], ans[a + 1][k]);
			// コストを使う
			const auto kl = min(k, N - a + 1);
			for(int i = 1; i <= kl; i++) {
				// コストを使用したら一個飛ばす
				ans[a][k] = max(ans[a][k], ans[a + i + 1][k - i] + flat[a][a + i - 1]);
			}
		}
	}

	const auto result = initial - ans[1][K];
	cout << result << endl;

	return 0;
}
