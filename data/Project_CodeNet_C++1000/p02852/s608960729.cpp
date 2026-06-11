#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
	queue<int> q;
	q.push(0);
	for (int i = n - 1; i >= 0; --i) {
		while (1) {
			if (q.size() == 0) {
				puts("-1");
				return 0;
			}
			if (q.front() != 1000000 && q.size() <= m) break;
			q.pop();
		}
		if (s[i] == '0') dp[i] = q.front() + 1;
		q.push(dp[i]);
	}

	if (dp[0] == 1000000) {
		cout << -1 << endl;
		return 0;
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