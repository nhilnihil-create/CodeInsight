//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <bitset>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000000000//10^18
#define INFINT 2000000001//2*10^9+1
#define MOD 1000000007
#define MODANOTHER 998244353
#define PI acos(-1)

using namespace std;

//static??
int culc(int n,int sint[1000010], int NumOfTwo[1000010]){

	int i,j,k,l;
	int flag;
	int temp;
	int ret;
	static int conbi[1000010];

	flag=0;
	for(i=0;i<n-1;i++){
		if(sint[i]==1){
			flag=1;
		}
	}

	for(i=0;i<n;i++){
		if(i==0){
			conbi[0]=0;
		}else{
			conbi[i]=conbi[i-1]+NumOfTwo[n-1-i]-NumOfTwo[i];
		}
	}


	/*for(i=0;i<n;i++){
		printf("conbi[%d]=%d\n",i,conbi[i]);
	}*/

	ret=0;
	if(flag==0){
		for(i=0;i<n-1;i++){
			if(conbi[i]==0&&sint[i]==2){
				ret=(ret+2)%4;
			}
		}
		return ret;
	}else{
		for(i=0;i<n-1;i++){
			if(conbi[i]==0&&sint[i]==1){
				ret=(ret+1)%2;
			}
		}
		return ret;
	}
}

int check(int n,int sint[1000010]){
	int i,j;

	int d[100][100];
	for(i=0;i<n-1;i++){
		d[0][i]=sint[i];
	}

	for(i=1;i<n;i++){
		for(j=0;j<n;j++){
			d[i][j]=abs(d[i-1][j+1]-d[i-1][j]);
		}
	}
	
	return d[n-2][0];
}

int main(void)
{
	//変数の宣言
	int n,m;
	int h,w;
	static char s[1000010];
	static int sint[1000010];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp=0;
	int temp1=0;
	int temp2=0;
	int temp3=0;
	static int vec[100010];
	int max=0;
	int min=INFINT;
	int len=0;
	int sum=0;
	int ok=0;
	int ng=0;
	char dummy;
	static char stemp[100010];
	
	//データの読み込み


	scanf("%d",&n);
//	scanf_s("%d",&n);


//	scanf("%s",&s);
//	scanf_s("%s",&s,1000010);


/*	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
//			scanf("%d",c[i][j]);
			scanf_s("%d",&c[i][j]);
		}
	}*/

	scanf("%c",&dummy);
	//scanf_s("%c",&dummy);
	for(i=0;i<n;i++){
		scanf("%c",&s[i]);
//		scanf_s("%c",&s[i]);
	}


/*	for(i=0;i<3;i++){
//		scanf("%s",&s);
		scanf_s("%s",&s[i],100010);
	}*/


	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

//	clock_t start=clock();

	for(i=0;i<n-1;i++){
		sint[i]=abs(s[i+1]-s[i]);
	}

	if(n==2){
		printf("%d",sint[0]);
		return 0;
	}

	static int NumOfTwo[1000010];

	for(i=1;i<=n;i++){
		NumOfTwo[i]=0;
		temp=i;
		while(temp%2==0){
			NumOfTwo[i]++;
			temp=temp/2;
		}
	}

	/*for(i=0;i<n;i++){
		printf("NumOfTwo[%d]=%d\n",i,NumOfTwo[i]);
	}*/

	printf("%d",culc(n,sint,NumOfTwo));
	
	/*for(i=0;i<243;i++){
		temp=i;
		j=0;
		while(j<6){
			sint[j]=temp%3;
			temp=temp/3;
			j++;
		}

		temp=culc(5,sint,NumOfTwo);
		temp2=check(5,sint);

		printf("[%d]:%d,%d\n",i,temp,temp2);
		if(temp!=temp2){
		//	printf("[%d]:%d,%d\n",i,temp,temp2);
			printf("不一致！！！！\n");
			printf("sint=");
			for(j=0;j<6;j++){
				printf("%d",sint[j]);
			}
			printf("\n");
		}
	}*/

//	clock_t end=clock();

	//	printf("計算部分終了\n");

	//出力
	
	//printf("%d",(d[i-1][j-1]+1)/2);

//	printf("time=%lf",(double)(end-start)/CLOCKS_PER_SEC);
	//	printf("結果の出力終了\n");

	return 0;
}

