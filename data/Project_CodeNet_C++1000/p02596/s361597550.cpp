#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI acos(-1.0)
#define test() int t; cin>>t; while(t--)
#define ll long long int

int main()
{
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int k;
	cin >> k;
	ll a = 7 % k;
	for (int i = 1; i < 1e7; i++) {
		if (a == 0) {
			cout << i << endl;
			return 0;
		}
		a = ((a * 10) + 7) % k;
	}
	cout << -1 << endl;
	return 0;
}
