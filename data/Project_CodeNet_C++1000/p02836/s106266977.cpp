#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	string s;
	cin >> s;
	string rs;
	rs = s;
	reverse(rs.begin(), rs.end());
	int ans = 0;
	rep(i, s.size())
	{
		if (s[i] != rs[i])
		{
			ans++;
		}
	}
	cout << ans/2 << "\n";
	return 0;
}