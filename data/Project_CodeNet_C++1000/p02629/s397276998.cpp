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
	ll n;
	cin >> n;
	string ans = "";
	while (n--) {
		ans += ('a' + n % 26);
		n /= 26;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
