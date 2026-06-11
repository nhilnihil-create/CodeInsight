#include"bits/stdc++.h"
using namespace std;
int a[2001][2001];
int h,w;

int main()
{
	
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif


	cin>>h>>w;
	vector<string> s(h);

	for(int i=0;i<h;i++)cin>>s[i]; //O(h*w)
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)if(s[i][j]=='.')a[i][j]=1;
	int ans=0;
	for(int i=0;i<h;i++)
	{
		int cur=0;
		for(int j=0;j<w;j++)
		{
			if(s[i][j]=='#')cur=0;
			else {a[i][j]+=cur;cur++;}
		}
		cur=0;
		for(int j=w-1;j>=0;j--)
		{
			if(s[i][j]=='#')cur=0;
			else {a[i][j]+=cur;cur++;}
		}
	}

	for(int j=0;j<w;j++)
	{
		int cur=0;
		for(int i=0;i<h;i++)
		{
			if(s[i][j]=='#')cur=0;
			else {a[i][j]+=cur;cur++;}
		}
		cur=0;
		for(int i=h-1;i>=0;i--)
		{
			if(s[i][j]=='#')cur=0;
			else {a[i][j]+=cur;cur++;}
		}
	}
	for(int i=0;i<h;i++)
		{for(int j=0;j<w;j++)
		{
			//cout<<a[i][j]<<" ";
			ans=max(ans,a[i][j]);
		}
		}
	cout<<ans;

}