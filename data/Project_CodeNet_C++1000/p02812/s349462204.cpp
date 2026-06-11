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
	int n;
	string s;
	cin >> n >> s;
	int ans=0;
	rep(i, n - 2)
	{
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
		{
			ans++;
		}
	}
	cout << ans << "\n";

	return 0;
}