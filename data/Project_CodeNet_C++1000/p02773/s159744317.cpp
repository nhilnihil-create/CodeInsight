#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;

	int maxCnt = 0;
	map<string, int> anstmp;
	for (int i = 0; i < N; ++i) {
		string S;
		cin >> S;
		anstmp[S]++;
		maxCnt = max(maxCnt, anstmp[S]);
	}

	vector<string> ans;
	for (auto i : anstmp) {
		if (i.second == maxCnt) {
			ans.push_back(i.first);
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}
