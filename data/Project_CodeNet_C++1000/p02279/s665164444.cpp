#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
using namespace std;

int main()
{
	int n;cin>>n;
	int k,c,d;
	vector <vector <int>> a(100000);
	int b[100010];
	for(int i=0;i<100000;b[i++]=-1);
	for(int i=0;i<n;i++)
	{
		cin>>k>>c;
		for(int j=0;j<c;j++)
		{
			cin>>d;
			b[d]=k;
			a[k].push_back(d);
		}
	}
	for(int i=0;i<n;i++)
	{
		int dep=1;
		if(b[i]!=-1)
		{
			for(k=b[i];b[k]!=-1;k=b[k],dep++);
		}
		else dep=0;
		cout<<"node "<<i<<": parent = "<<b[i]<<", depth = "<<dep<<", ";
		
		if(b[i]==-1)cout<<"root";
		else if(a[i].size()==0)cout<<"leaf";
		else cout<<"internal node";
		
		cout<<", [";
		if(a[i].size())
		{
			
			for(int j=0;j<a[i].size();j++)
			{
				if(j==0)cout<<a[i][0];
				else cout<<", "<<a[i][j];
			}
		}
		cout<<"]"<<endl;
	}
	return 0;
}