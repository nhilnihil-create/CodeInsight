#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define ff first
#define ss second
#define prec(y,x) fixed<<setprecision(y)<<x
#define inf 1e18
#define pi 3.1415926535

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		int a = s[i] - 'A' + 1;
		a += n;
		if (a >= 27)
			a++;
		a %= 27;
		// a++;
		char c = 'A' - 1 + a;
		s[i] = c;
	}
	cout << s;
	return 0;
}

