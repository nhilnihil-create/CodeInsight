#include <bits/stdc++.h>
using namespace std;
 
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
 
int main()
{
	string in;
	cin >> in;
	auto re = runLength(in);
	int res[100001] = {};
	int count = 0;
	for (int i = 0; i < re.size() - 1; i += 2)
	{
		res[count + re[i].second-1] = 1 + (re[i].second-1) / 2 + re[i+1].second / 2;
		res[count + re[i].second] = 1 + re[i].second / 2 + (re[i+1].second-1)/2;
		count += re[i].second + re[i + 1].second;
	}
	for (int i = 0; i < in.size(); ++i)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}