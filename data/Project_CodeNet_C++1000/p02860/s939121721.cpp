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
	bool ans = true;
	int n;
	string s;
	cin >> n >> s;
	if (n % 2 != 0)
	{
		ans = false;
	}
	else
	{
		rep(i, n / 2)
		{
			if (s[i] != s[i + (n / 2)])
			{
				ans = false;
			}
		}
	}

	if (ans) cout << "Yes" << "\n";
	else cout << "No" << "\n";

	return 0;
}