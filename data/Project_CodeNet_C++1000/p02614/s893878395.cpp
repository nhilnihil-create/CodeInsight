#include<bits/stdc++.h>
using namespace std;
string s;
//int a,b,c,d;
char a[10][10];
int sum;
int ans;
int main()
{
	int h,w,k;cin>>h>>w>>k;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='#')
			{
				sum++;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<(1<<h);i++)
	{
		for(int j=0;j<(1<<w);j++)
		{
			cnt=0;
			for(int x=0;x<h;x++)
			{
				for(int y=0;y<w;y++)
				{
					if(((i&(1<<x))||(j&(1<<y)))&&a[x][y]=='#')cnt++;
				}
			}
			if(cnt==sum-k)
			{
				ans++;
			}
		}
	}
	cout<<ans;
}