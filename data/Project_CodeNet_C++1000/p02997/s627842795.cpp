#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n,k;
	cin >> n >> k;
	int hoge = (n-2)*(n-1)/2;
	if(hoge<k)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<pair<int,int>> ans,dis2;

	for(int i = 2;i<=n;i++)
	{
		ans.emplace_back(1,i);
	}

	for(int i = 2;i<n;i++)
	{
		for(int j = i+1;j <= n;j++)
		{
			dis2.emplace_back(i,j);
		}
	}
	while(dis2.size()!=k)
	{
		ans.push_back(dis2.back());
		dis2.pop_back();
	}
	cout << ans.size() << endl;

	for(auto i:ans)
	{
		cout << i.first << ' '<<i.second << endl;
	}
	
}
