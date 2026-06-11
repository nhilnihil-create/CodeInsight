#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int>l(n);
	for (int i = 0; i < n; i++)cin >> l.at(i);
	ll ans = 1;
	ll pos = 0;
	for (int i = 0; i < n; i++) {
		pos += l.at(i);
		if (pos <= x)ans++;
		else break;
	}
	cout << ans << endl;
}