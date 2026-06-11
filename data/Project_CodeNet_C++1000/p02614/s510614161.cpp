#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<cmath>
#include<map> 
#include<string>
#include<queue>
#include<stack> 
#include<bitset>
#include<list>
#include<set>
#include<utility>
#define IO ios::sync_with_stdio(false)
//#define int long long
using namespace std;
char c[10][10];
int h,w,k;
int main()
{
	IO;
	cin>>h>>w>>k;
	int ans=0;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int i=0;i<(1<<h);i++)
	{
		for(int j=0;j<(1<<w);j++)
		{
			int num=0;
			for(int ii=0;ii<h;ii++)
			{
				for(int jj=0;jj<w;jj++)
				{
					if(!(i&(1<<ii))&&!(j&(1<<jj))&&c[ii][jj]=='#')num++;
				}
			}
			if(num==k)ans++;
		}
	}
	cout<<ans;
}