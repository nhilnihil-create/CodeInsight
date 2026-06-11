#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> ve[N];
priority_queue<int> qe;
int n,m;
int main()
{
	cin>>n>>m;
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		if(m-x+1<1)
			continue;
		ve[m-x+1].push_back(y); 
	}
	int sum=0;
	for(int i=m;i>=1;i--)
	{
		for(int j=0;j<ve[i].size();j++)
			qe.push(ve[i][j]);
		if(!qe.empty())
			sum+=qe.top(),qe.pop();
	}
	cout<<sum<<"\n";
}