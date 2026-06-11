#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(n,x) for(ll i=0;i<n;i++) cin>>x[i];


int main()
{
	double a, b, x;
	cin >> a >> b >> x;
	double ans;
	if (a * a * b <= 2 * x)
	{
		ans = atan((2 * a * a * b - 2 * x) / (a * a * a));
	}
	else
	{
		ans = atan(a * b * b / (2 * x));
	}
  
	double p = 3.1415926535;
	ans *= 180 / p;
	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}