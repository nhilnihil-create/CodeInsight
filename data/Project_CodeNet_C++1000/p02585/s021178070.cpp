#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;
long long int n,k,p[5002];
long long int ans=-1000000000000,c[5002];
int main()
{
 scanf("%lld %lld",&n,&k);
 for(long long int i=1;i<=n;i++)
 {
	scanf("%lld",&p[i]);
 }
 for(long long int i=1;i<=n;i++)
 {
	scanf("%lld",&c[i]);
 }
 for(long long int i=1;i<=n;i++)
 {
	long long int nw=i;
	long long int lpt=0;
	long long int lpsx=0;//lpt:ループを回すのに必要な回数 lpsx:ループを回したときのスコア
	for(;;)
	{
		lpt++;
		nw=p[nw];lpsx+=c[nw];
		if(nw==i){break;}
	}
	long long int lpc;//ループを回す回数
	if(lpsx>=0){lpc=k/lpt;}
	else{lpc=0;}
	long long int scr=0;
	scr=lpc*lpsx; //ループ部分でのスコア
	long long int kz=k-lpc*lpt; //kzは残り動ける回数、この中で得点を最大化する。
	long long int zw=-100000000000,zn=0;
	long long int mv=0;
	if(lpc==0)
	{
	for(long long int l=1;l<=min(kz,lpt);l++)
	{
		nw=p[nw];zn+=c[nw];
		if(zw<zn){mv=l; zw=zn;}
	}
	}
	else
	{
	scr-=lpsx; kz+=lpt;
	for(long long int l=1;l<=kz;l++)
	{	
		nw=p[nw];zn+=c[nw];
		if(zw<zn){mv=l; zw=zn;}
	}
	zw=max(zw,0LL);
	}
	scr+=zw;
	ans=max(ans,scr);
 }
 printf("%lld",ans);
}

