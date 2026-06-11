#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	cout << fixed << setprecision(10);
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	double ans = 0;
	for (int i = 0; i < n; i++)ans += (double)1 / a.at(i);
	ans = 1 / ans;
	cout << ans << endl;
}