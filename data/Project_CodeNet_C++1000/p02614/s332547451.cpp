#include<bits/stdc++.h>
#define N 1000005
#define LL long long
using namespace std;

LL ans;
int h,w,k;
char a[66][66];
int bo1[14],bo2[14];

inline int qr()
{
	int x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

void dfs2(int lie)
{
	if(lie>w)
	{
//		for(int i=1;i<=h;i++)
//			cout<<bo1[i]<<' ';
//		cout<<endl;
//		for(int i=1;i<=w;i++)
//			cout<<bo2[i]<<' ';
//		cout<<endl;
		int cnt=0;
		for(register int i=1;i<=h;i++)
			for(register int j=1;j<=w;j++)
			{
				if(bo1[i]||bo2[j])
					continue;
				if(a[i][j]=='#')
					cnt++;
			}
		if(cnt==k)
			ans++;
		//cout<<cnt<<endl;
		return ;
	}
	bo2[lie]=1;
	dfs2(lie+1);
	bo2[lie]=0;
	dfs2(lie+1);
}

void dfs1(int hang)
{
	if(hang>h)
	{
//		for(int i=1;i<=h;i++)
//			cout<<bo1[i]<<' ';
//		cout<<endl;
		dfs2(1);
		return ;
	}
	bo1[hang]=1;
	dfs1(hang+1);
	bo1[hang]=0;
	dfs1(hang+1);
}

int main()
{
	h=qr();
	w=qr();
	k=qr();
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)	
			cin>>a[i][j];
	dfs1(1);
	cout<<ans<<endl;
	return 0;
} 