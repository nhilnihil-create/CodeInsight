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
int main()
{
 int k;
 scanf("%d",&k);
 int flg=1,nw=0,rep=7%k;
 for(int i=1;i<=k;i++)
 {
	nw+=rep;
	nw=nw%k;
	rep=(rep*10)%k;
	if(nw==0){printf("%d",i); flg=0; break;}
 }
 if(flg==1){printf("-1");}
}