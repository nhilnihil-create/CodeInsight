#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	vector<int> dp(n + 1, 1000000);
	dp[n] = 0;
	for (int i = n - 1; 0 <= i; --i) {
		if (s[i] == '1') {
			continue;
		}

		int next = i + m;
		if (n < next) {
			next = n;
		}
		while (next != i)
		{
			if (dp[next] != 1000000) {
				dp[i] = dp[next] + 1;
				break;
			}
			--next;
		}
		if (dp[i] == 1000000) {
			cout << -1 << endl;
			return 0;
		}
	}

	int count = 0;
	int prev = dp[0];
	for (auto& i : dp) {
		if (i == 1000000) {
			++count;
			continue;
		}
		if (prev != i) {
			cout << count << " ";
			count = 0;
		}
		prev = i;
		++count;
	}
	cout << endl;

	return 0;
}