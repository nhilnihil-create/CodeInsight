#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[112345];
int main() {
	int n, i;
	cin >> n;
	for (i = 0; i < n; ++i)cin >> a[i];
	sort(a, a + n);
	vector<pair<int, int>>t;
	int cnt = 0;
	t.push_back({ a[0],1 });
	for (i = 1; i < n; ++i) {
		if (a[i] != a[i - 1]) {
			t.push_back({ a[i],1 });
			++cnt;
		}
		else t[cnt].second++;
		if (cnt >= 3)break;
	}
	if (cnt >= 3)cout << "No" << endl;
	else if (cnt == 0) {
		if (t[0].first == 0)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else {
		if (n % 3)cout << "No" << endl;
		else {
			if (cnt == 1) {
				if (t[0].first == 0 && t[0].second == (n / 3))cout << "Yes" << endl;
				else cout << "No" << endl;
			}
			else {
				if (t[0].second == t[1].second && t[1].second == t[2].second) {
					if ((t[0].first ^ t[1].first ^ t[2].first) == 0)cout << "Yes" << endl;
					else cout << "No" << endl;
				}
				else cout << "No" << endl;
			}
		}
	}
}