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
    double a;
	int  b;
	cin >> a >> b;

	int x, y;
	int ans;
	int p = ceil(25 * a / 2);
	ans = max(p, 10 * b);

	if (4 * b + 4 <= 5 * a || 5 * a + 5 <= 4 * b)
	{
		ans = -1;
	}
	cout << ans << "\n";

	return 0;
}