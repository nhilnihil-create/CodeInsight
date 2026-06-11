#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	vector<int>ans(n,0);
	for (int i = n; i >= 1; i--) {
		int res = 0;
		int x = (n/i)*i;
		while (x > 0) {
			res += ans.at(x - 1);
			x -= i;
		}
		res %= 2;
		ans.at(i-1) = abs(a.at(i-1) - res);
	}
	//cout << ans.at(0) << ans.at(1) << ans.at(2) << ans.at(3) << ans.at(4) << endl;
	int k = 0;
	for (int i = 0; i < n; i++)k += ans.at(i);
	cout << k << endl;
	bool fi = true;
	for (int i = 0; i < n; i++) {
		if (fi == true && ans.at(i) == 1) {
			cout << i+1;
			fi = false;
		}
		else if (ans.at(i) == 1)cout << " " << i+1;
	}
	if(k!=0)cout << endl;
}