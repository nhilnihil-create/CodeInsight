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
	int n, x;
	cin >> n >> x;
	vector<int> l(n);
	for (int i = 0; i < n; i++) cin >> l[i];
	int sum,  ans;
	sum = 0;
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans++;
		sum += l[i];
		if (x < sum)
		{
			break;
		}
	}
	if (sum <= x) ans++;

	cout << ans << "\n";

	return 0;
}