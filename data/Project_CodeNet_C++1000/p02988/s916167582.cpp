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
	vector<int> p(n);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	int ans = 0;
	for (int t = 0; t < n - 2; t++)
	{
		if ((p[t] < p[t + 1] && p[t + 1] < p[t + 2])||(p[t] > p[t + 1] && p[t + 1] > p[t + 2]))
		{
			ans++;
		}
	}

	cout << ans << "\n";


	return 0;
}