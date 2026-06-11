#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int h,w,m;
	cin >> h >> w >> m;
	int ans = 0;
	vector<pair<int,int>> vp(m);
	for(int i = 0;i<m;i++)
	{
		cin >> vp[i].first >> vp[i].second;
		vp[i].first--;vp[i].second--;
	}
	vector<int> nowboms(h);	
	vector<int> tmp(w);
	vector<vector<int>> boms(h);
	multiset<int> yoko;
	{
		for(int i = 0;i<m;i++)
		{
			tmp[vp[i].second]++;
			nowboms[vp[i].first]++;
			boms[vp[i].first].push_back(vp[i].second);
		}
		for(int i = 0;i<w;i++)yoko.insert(tmp[i]);
	}
	for(int i = 0;i<h;i++)
	{
		multiset<int> onboms;
		for(int j =0;j<boms[i].size();j++)
		{
			onboms.insert(tmp[boms[i][j]]);
			yoko.erase(yoko.find(tmp[boms[i][j]]));
		}
		if(yoko.size())ans = max(ans,*yoko.rbegin()+nowboms[i]);
		if(onboms.size())ans = max(ans,*onboms.rbegin()+nowboms[i]-1);
		for(int j = 0;j<boms[i].size();j++)
		{
			yoko.insert(tmp[boms[i][j]]);
		}
	}

	cout<<ans<<endl;
}
