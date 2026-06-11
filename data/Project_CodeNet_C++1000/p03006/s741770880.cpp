#include<bits/stdc++.h>
#include<map>
#include<iosfwd>
#include<ios>
#include<istream>
#include<sstream>
#include<complex>
#include<ccomplex>
using namespace std;
typedef pair<int,int> P;
map<P,int> mp;
int main()
{
	int n;
	cin>>n;
	vector<P> vp;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		vp.push_back(make_pair(x,y));
	}
	int sum = 0;
//	cout<<n<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			int dx = vp[j].first - vp[i].first;
			int dy = vp[j].second - vp[i].second;
			mp[P(dx,dy)]++;
			mp[P(-dx,-dy)]++;
//			cout<<i<<endl;
		}
	}
	for(map<P,int>::iterator it = mp.begin();it!=mp.end();it++)
	{
		if(it->second>sum)
			sum = it->second;
	}
	cout<<n-sum<<endl;
	return 0;
}