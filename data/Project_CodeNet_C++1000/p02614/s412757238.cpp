#include<cstdio>
#include<functional>
#include<algorithm>
#include<cstring>
using namespace std;
void funch(int);
void funcw(int);
int h,w,k,h1[6],w1[6],cnt;
char c[6][7];
int main(void)
{
	int i;
	scanf("%d %d %d",&h,&w,&k);
	for(i=0;i<h;i++)	scanf("%s",c[i]);
	cnt=0;
	funch(0);
	printf("%d\n",cnt);
	return 0;
}
void funch(int nh)	
{
	if(nh==h)	{
		funcw(0);
	}
	else {
		h1[nh]=0;
		funch(nh+1);
		h1[nh]=1;
		funch(nh+1);
	}
}
void funcw(int nw)
{
	int i,j,cc;
	if(nw==w)	{
		cc=0;
		for(i=0;i<h;i++)	{
			for(j=0;j<w;j++)	{
				if(h1[i]==0 && w1[j]==0 && c[i][j]=='#') cc++;
			}
		}
		if(cc==k) cnt++;
	}
	else {
		w1[nw]=0;
		funcw(nw+1);
		w1[nw]=1;
		funcw(nw+1);
	}
}