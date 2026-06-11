#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void print(const vector<int>& v)
{
	for (const auto& item : v) {
		cout << item << " ";
	}
}

int main()
{
	string s;
	cin >> s;
	int n = s.size();

	vector<int> ans(n);
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') count++;
		else {
			ans[i] += count / 2;
			ans[i - 1] += (count + 1) / 2;
			count = 0;
		}
	}

	reverse(ans.begin(), ans.end());
	reverse(s.begin(), s.end());

	count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') count++;
		else {
			ans[i] += count / 2;
			ans[i - 1] += (count + 1) / 2;
			count = 0;
		}
	}

	reverse(ans.begin(), ans.end());
	reverse(s.begin(), s.end());

	for (int i = 0; i < n; i++) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
}
