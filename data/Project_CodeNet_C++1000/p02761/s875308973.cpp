#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n, m;
	cin >> n >> m;
	string ans;
	if (n == 1) {
		ans = "00";
		for (int i = 0; i < m; i++) {
			int in, num;
			cin >> in >> num;
			if (in == 1 && ans[in] == '0') {
				//cout << "1";
				ans[in] = num + '0';
			} else if (in == 1 && ans[in] != num + '0')
				return cout << "-1", 0;
			else if (ans[in] == '0' && in != 1) {
				//cout << "3";
				ans[in] = num + '0';
			} else if (ans[in] != num + '0' && in != 1) {

				return cout << "-1", 0;
			}
		}
		cout << ans[1];
	} else {
		ans = "0100";

		for (int i = 0; i < m; i++) {
			int in, num;
			cin >> in >> num;

			if (in == 1 && ans[in] == '1') {
				//cout << "1";
				ans[in] = num + '0';
			} else if (in == 1 && ans[in] != num + '0')
				return cout << "-1", 0;
			else if (ans[in] == '0' && in != 1) {
				//cout << "3";
				ans[in] = num + '0';
			} else if (ans[in] != num + '0' && in != 1) {

				return cout << "-1", 0;
			}
		}
		if (ans[1] == '0')
			return cout << "-1", 0;
		for (int i = 1; i <= n; i++)
			cout << ans[i];
	}
}
