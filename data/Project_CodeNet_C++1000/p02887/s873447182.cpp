#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)


int main()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;
	char x = s[0];
	ll ans = 1;
	for (ll i = 1; i < n; i++)
	{
		if (x != s[i])
		{
			ans++;
			x = s[i];
		}
	}
	cout << ans << "\n";
	return 0;
}