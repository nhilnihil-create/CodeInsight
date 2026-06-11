#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	string s; cin >> s;
	int w_cnt = 0;
	int r_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') w_cnt++;
		else r_cnt++;
	}
	string t = "";
	for (int i = 0; i < r_cnt; i++) t += "R";
	for (int i = 0; i < w_cnt; i++) t += "W";
	int diff_w_cnt = 0;
	int diff_r_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R' && t[i] =='W') {
			diff_r_cnt++;
		}
		else if (s[i] == 'W' && t[i] == 'R') {
			diff_w_cnt++;
		}
	}
	int ans = 0;
	ans += min(diff_r_cnt, diff_w_cnt);
	ans += abs(diff_r_cnt - diff_w_cnt);
	cout << ans << endl;
    return 0;
}