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
	int n = s.size();
	bool ans = true;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			if (s[i] == 'L') ans = false;
		}
		else
		{
			if (s[i] == 'R') ans = false;
		}
	}

	if (ans) cout << "Yes" << "\n";
	else cout << "No" << "\n";
	return 0;
}