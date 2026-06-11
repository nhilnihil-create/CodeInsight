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
	int n, d;
	cin >> n >> d;
	vector<vector<int>> x(n, vector<int>(d));
	rep(p, n)rep(q, d) cin >> x[p][q];
	int ans = 0;
	int a;
	for(int i=0;i<n;i++)
	{
		for (int t = i + 1; t < n; t++)
		{
			a = 0;
			for(int p = 0; p < d ; p++ )
			{
				a += (x[i][p] - x[t][p])*(x[i][p] - x[t][p]);
			}
 
			for (int q = 1; q <= a; q++)
			{
				if (q * q == a)
				{
					ans++;
				}
			}

		}
	}

	cout << ans << "\n";
	return 0;
}