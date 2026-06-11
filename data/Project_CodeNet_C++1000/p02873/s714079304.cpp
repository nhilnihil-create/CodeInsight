#include <bits/stdc++.h>
using namespace std;
static const int INFH = (1<<30)-1;
static const int INFL = -INFH;
 
vector<pair<char, int>> runLength(string x)
{
	char now = x[0];
	int count = 1;
	vector<pair<char, int>> ret;
	for (int i = 1; i < x.size(); ++i)
	{
		if(x[i] != now)
		{
			ret.push_back(make_pair(now, count));
			now = x[i];
			count = 1;
		}
		else
		{
			++count;
		}
	}
	ret.push_back(make_pair(now, count));
	return ret;
}
 
long long int wa(int x)
{
	long long int ret = 0;
	for (int i = 1; i <= x; ++i)
	{
		ret += i;
	}
	return ret;
}
 
int main()
{
	string in;
	cin >> in;
	vector<pair<char, int>> r = runLength(in);
	long long int ans = 0;
	if(r.size() == 1)
	{
		cout << wa(r[0].second) << endl;
		return 0;
	}
	for (int i = 0; i < r.size(); ++i)
	{
		if(i == 0 && r[i].first == '>')
		{
			ans += wa(r[i].second);
		}
		else if (i == r.size() - 1 && r[i].first == '<')
		{
			ans += wa(r[i].second);
		}
		else
		{
			ans += wa(max(r[i].second, r[i + 1].second)) + wa(min(r[i].second, r[i + 1].second)-1);
			++i;
		}
	}
	cout << ans << endl;
	return 0;
}