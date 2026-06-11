#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long int ll;
const ll INF=pow(10,15);
const ll md=pow(10,9)+7;

//20
ll conbi[2001][2001]={};


int main()
{
 conbi[0][0]=1;
 for(int i=1;i<=2000;i++)
 {
	for(int j=0;j<=i;j++)
	{	
		if(j==0){conbi[i][j]=1;}
		else{conbi[i][j]=(conbi[i-1][j-1]+conbi[i-1][j])%md;}
	}
 }
 int N,K;
 scanf("%d %d",&N,&K);
 for(int r=1;r<=K;r++)
 {
	ll ans=(conbi[K-1][r-1]*conbi[N-K+1][r])%md;
	printf("%lld\n",ans);
 }
}