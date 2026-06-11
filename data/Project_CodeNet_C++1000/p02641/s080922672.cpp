#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI acos(-1.0)
#define test() int t; cin>>t; while(t--)
#define ll long long int
int mod = 1e9 + 7;
int main()
{
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x, n;
	cin >> x >> n;
	if (n == 0) {
		cout << x << endl;
		return 0;
	}
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= x; i++) {
		for (int pol : { -1, 1}) {
			int cur = x + i * pol;
			if (count(a.begin(), a.end(), cur) == 0) {
				cout << cur << endl;
				return 0;
			}
		}
	}
	return 0;
}
