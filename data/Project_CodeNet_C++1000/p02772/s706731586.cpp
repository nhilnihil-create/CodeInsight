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
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	bool ans = true;
	rep(i, n)
	{
		if (a[i] % 2 == 0)
		{
			if (a[i] % 3 != 0 && a[i] % 5 != 0)
			{
				ans = false;
			}
		}
	}
	if (ans) cout << "APPROVED" << "\n";
	else cout << "DENIED" << "\n";
	return 0;
}