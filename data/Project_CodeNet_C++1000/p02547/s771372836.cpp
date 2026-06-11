#include<bits/stdc++.h>
#include<cstring>
// #include<queue>
#include<vector>
#include<utility>
using namespace std;
int inf=1e9;
//vector<long long int>adj[10000];

int main()
{
	int n;
	cin>>n;
	int a[n],b[n],c[n];

	for(int i=0;i<n;i++)
	{
		c[i]=0;
		cin>>a[i]>>b[i];
		if(a[i]==b[i])c[i]=1;
	}
	for(int i=0;i<n-2;i++)
	{
		if(c[i]==1 && c[i+1]==1 && c[i+2]==1)
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}
