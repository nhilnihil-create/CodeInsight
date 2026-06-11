#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int prime[1000000]={}; //i番目の素数
int spf[10000001];//1~1000000までSPFを求めておく
bool is_prime[1000001]; //is_primeがtrueならiは素数
void sieve(int n) //n以下の素数を列挙する
{
	int p=0;
	for(int i=0; i<=n;i++){ is_prime[i]=true; spf[i]=i;}
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(is_prime[i])
		{
			prime[p++]=i;
			for(int j=2*i;j<=n;j+=i){ is_prime[j]=false; spf[j]=i;}
		}
	}
}


int main()
{
 int x,ans=0;
 scanf("%d",&x);
 sieve(x);
//printf("aa");
 for(int i=1;i<x;i++)
 {
	int rep=x-i,med=1,tet=0,mae=1;//x-iの約数の個数がmed
	if(rep==1){ans++; break;}
	if(is_prime[rep]){med=2;}
	else{
	for(;;)
	{
		mae=spf[rep];//repを割り切る最小の素数を記録しておく
		rep/=mae;
		tet++;
		if(mae!=spf[rep]){med=med*(tet+1);tet=0;}
		if(rep==1){break;}
	}
	}
	ans+=med;
//	printf("%d %d\n",x-i,med);
 }
 printf("%d",ans);
}
