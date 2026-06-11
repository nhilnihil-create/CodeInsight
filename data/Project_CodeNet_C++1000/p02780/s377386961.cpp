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
	double n, k;
	cin >> n >> k;
	vector<double> p(n);
	for (ll i = 0; i < n; i++)cin >> p[i];
	ll sum, max;
	max = -1;
	vector<double> s(n+1);
	s[0] = 0;
	for (ll i = 0; i < n + 1 ; i++)
	{
		s[i + 1] = s[i] + p[i];
	}
	for (ll i = 0; i < n - k +1; i++)
	{
		sum = s[i + k] - s[i];
		if (max < sum)
		{
			max = sum;
		}
	}

	double ans;
	ans = (max + k) / 2;
	cout <<fixed<<setprecision(10)<< ans << "\n";

	return 0;
}