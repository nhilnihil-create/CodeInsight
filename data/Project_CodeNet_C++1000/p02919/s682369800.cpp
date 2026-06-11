#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int n;
ll ans;
int Arr[N];
int dp[2][N][2];
// L & R - index - first or second?

void calc(int d) {
	vector <int> s1, s2, add;

	for (int i = 0; i < n; i++) {
		dp[d][i][0] = dp[d][i][1] = -1;

		while (s2.size() && Arr[s2.back()] < Arr[i])
			s2.pop_back();
		if (s2.size())
			dp[d][i][1] = max(dp[d][i][1], s2.back());


		while (s1.size() && Arr[s1.back()] < Arr[i]) {
			add.push_back(s1.back());
			s1.pop_back();
		}

		while (add.size()) {
			while (s2.size() && Arr[s2.back()] < Arr[add.back()])
				s2.pop_back();

			s2.push_back(add.back());
			add.pop_back();
		}

		if (s1.size()) {
			dp[d][i][0] = s1.back();
			if (1 < s1.size())
				dp[d][i][1] = max(dp[d][i][1], s1[s1.size() - 2]);
		}
		s1.push_back(i);
	}

	s1.clear();
	s2.clear();
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &Arr[i]);

	calc(0);
	reverse(Arr, Arr + n);
	calc(1);
	reverse(Arr, Arr + n);
	for (int i = 0; i < n; i++)
		for (int id = 0; id < 2; id++)
			if (dp[1][i][id] != -1)
				dp[1][i][id] = n - 1 - dp[1][i][id];
	for (int i = 0, j = n - 1; i < j; i++, j--)
		swap(dp[1][i], dp[1][j]);

	for (int i = 0; i < n; i++) {
		ll l, r;
		if (dp[0][i][0] != -1) {
			l = dp[0][i][1] + 1;
			r = dp[1][i][0] - 1;
			if (dp[1][i][0] == -1)
				r = n - 1;

			ans += (dp[0][i][0] - l + 1) * (r - i + 1) * Arr[i];
		}
		if (dp[1][i][0] != -1) {
			l = dp[0][i][0] + 1;
			r = dp[1][i][1] - 1;
			if (dp[1][i][1] == -1)
				r = n - 1;

			ans += (i - l + 1) * (r - dp[1][i][0] + 1) * Arr[i];
		}
	}

	printf("%lld", ans);
	return 0;
}