#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main()
{
	int a[100];
	memset(a,0,sizeof(a));
	int in;
	while(cin>>in)a[in-1]++;
	vector<pair<int,int>> P;
	rep(i,100)P.push_back(make_pair(a[i],i));
	sort(P.begin(),P.end(),[](const pair<int,int> p1,const pair<int,int> p2)
	{
		return p1.first==p2.first?p1.second>p2.second:p1.first<p2.first;
	});
	cout<<P[99].second+1<<endl;
	int c=99;
	while(P[c].first==P[c-1].first)
	{
		cout<<P[--c].second+1<<endl;
	}
	return 0;
}