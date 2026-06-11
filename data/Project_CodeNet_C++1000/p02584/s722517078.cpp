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
	ll x, k, d;
	cin >> x >> k >> d;
	x = abs(x);
	ll a = min(k, x / d);
	k -= a;
	x -= a * d;
	if (k & 1) {
		cout << d - x << endl;
	}
	else	cout << x << endl;
	return 0;
}
