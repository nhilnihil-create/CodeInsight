#include <bits/stdc++.h>
using namespace std;
#define test() int t; cin>>t; while(t--)
#define ll long long int
int mod = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(n);
	double p = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		p += a[i];
	}
	p = round(p / n);
	double ans = 0;
	for (int i : a) {
		ans += (i - p) * (i - p);
	}
	cout << ans << endl;

	return 0;
}