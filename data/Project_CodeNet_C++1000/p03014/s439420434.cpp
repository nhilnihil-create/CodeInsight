#include<cstdio>
#include<string>
#include<cstring>
#include<utility>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define inf 0x7fffffff
using namespace std;
string s[2010];
int a[2010][2010],b[2010][2010];
int numa[2010*2010],numb[2010*2010];
int main()
{
	int i,j,k,n,m,x,y,h=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(i=0;i<n;i++)
	{
		x=0;
		for(j=0;j<m;j++)
		{
			if(s[i][j]=='#')
			{
				if(x>0)
				{
					numa[h]=x;
					x=0;
					h++;
				}
			}
			else
			{
				a[i][j]=h;
				x++;
			}
		}
		if(x>0)
		{
			numa[h]=x;
			h++;
		}
	}
	h=0;
	for(i=0;i<m;i++)
	{
		x=0;
		for(j=0;j<n;j++)
		{
			if(s[j][i]=='#')
			{
				if(x>0)
				{
					numb[h]=x;
					x=0;
					h++;
				}
			}
			else
			{
				b[j][i]=h;
				x++;
			}
		}
		if(x>0)
		{
			numb[h]=x;
			h++;
		}
	}
	int ma=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			ma=max(ma,numa[a[i][j]]+numb[b[i][j]]-1);
		}
	}
	printf("%d",ma);
	return 0;
}

