#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	s.push_back('<');

	int sz = s.size();
	int cnt_L = 0, cnt_R = 0;
	long long ans = 0;
	for (int i = 0; i < sz; ++i) {
		if (s[i] == '<') cnt_L++;
		else cnt_R++;
		if (s[i] == '>' && s[i + 1] == '<') {
			ans += (long long)max(cnt_L, cnt_R) * (max(cnt_L, cnt_R) + 1) / 2;
			ans += (long long)min(cnt_L, cnt_R) * (min(cnt_L, cnt_R) - 1) / 2;
			cnt_L = 0;
			cnt_R = 0;
		}
	}

	s.pop_back();
	s = '>' + s;
	int cnt = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '<') cnt++;
		else {
			ans += (long long)cnt * (cnt + 1) / 2;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}
