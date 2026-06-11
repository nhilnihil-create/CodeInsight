#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	pair<double,double> xy[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>xy[i].first>>xy[i].second;
	}
	sort(xy, xy+n, [](const auto &p1, const auto &p2) {return atan2(p1.second, p1.first) < atan2(p2.second, p2.first);});
	double ans=.0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < i+n; ++j)
		{
			double xn=.0,yn=.0;
			for (int k = i; k <= j; ++k)
			{
				xn+=xy[k%n].first;
				yn+=xy[k%n].second;
			}
			ans=max(ans,sqrt((xn*xn+yn*yn)));
		}
	}
	printf("%.11f\n", ans);
	return 0;
}
