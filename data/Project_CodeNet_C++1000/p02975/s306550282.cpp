#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int q=0; q<=30; q++) {
		int cnt = 0;
		for (int i=0; i<n; i++) {
			if (!((a[i]>>q)&1)) {
				cnt ++;
			}
		}
		if (cnt == n) continue;
		bool flag = 0;
		for (int i=0; i<=2; i++) {
			if ((n+2-i)/3 != cnt) continue;
			flag = 1;
		}
		if (!flag) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
