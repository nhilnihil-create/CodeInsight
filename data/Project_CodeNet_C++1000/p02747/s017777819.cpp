#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s, ans;
	cin >> s;
	rep(i, 5)
	{
		ans += "hi";
		if (ans == s)
		{
			cout << "Yes" << endl;	
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
