#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
ll n, ans;
int Arr[N];
int dp[2][N][2];
// L & R - index - first or second?

void calc(int d) {
	vector <int> vec1, vec2, add;

	for (int i = 0; i < n; i++) {
		dp[d][i][0] = dp[d][i][1] = -1;

		while (vec2.size() && Arr[vec2.back()] < Arr[i])
			vec2.pop_back();
		if (vec2.size())
			dp[d][i][1] = max(dp[d][i][1], vec2.back());


		while (vec1.size() && Arr[vec1.back()] < Arr[i]) {
			add.push_back(vec1.back());
			vec1.pop_back();
		}

		while (add.size()) {
			while (vec2.size() && Arr[vec2.back()] < Arr[add.back()])
				vec2.pop_back();

			vec2.push_back(add.back());
			add.pop_back();
		}

		if (vec1.size()) {
			dp[d][i][0] = vec1.back();
			if (1 < vec1.size())
				dp[d][i][1] = max(dp[d][i][1], vec1[vec1.size() - 2]);
		}
		vec1.push_back(i);
	}

	vec1.clear();
	vec2.clear();
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> Arr[i];

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

	cout << ans << "\n";
	return 0;
}
