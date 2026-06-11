#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,x,y;
	vector <pair<int,int>> p;
	double res = 0;

	cin >> n;

	for(int i=0;i<n;i++)
	{
		cin >> x >> y;
		p.push_back(make_pair(x,y));
	}

	vector <int> perm;
	for(int i=0;i<n;i++)
	{
		perm.push_back(i);
	}

	int total = 0;
	do
	{
		total++;
		double dist = 0;
		for(int i=1;i<n;i++)
		{
			double dx = p[perm[i]].first - p[perm[i-1]].first;
			double dy = p[perm[i]].second - p[perm[i-1]].second;
			double d = sqrt(dx*dx + dy*dy);
			dist += d;
		}
		res += dist;
	}while(next_permutation(perm.begin(),perm.end()));
	res/=total;

	cout << fixed;
	cout.precision(16);

	cout << res << '\n';

	return 0;
}
