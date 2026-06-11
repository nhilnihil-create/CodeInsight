#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	int wacount[n];
	fill(wacount, wacount+n, 0);
	bool d[n];
	fill(d, d+n, false);

	//long long wacount = 0;
	long long account = 0;
	for (int i = 0; i < m; i++) {
		int p;
		string s;
		cin >> p >> s;
		if (d[p-1] == true) {
			continue;
		}

		if (s == "WA") {
			wacount[p-1]++;
		} else {
			d[p-1] = true;
			account++;
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (d[i])
			ans += wacount[i];
	}
	cout << account << " " << ans << endl;
	return 0;
}