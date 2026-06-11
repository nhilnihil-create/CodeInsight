//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
#define debug1 cout<<"?"<<endl;
#define debug2 cout<<"?"<<i<<endl;
#define PII pair<int,int>
typedef long long ll;
const int maxn=1e6+9;
const double pi=acos(-1);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double ep=1e-7;
using namespace std;
int main()
{
	char s[maxn];
	scanf("%s",s+1);
	int i,len=strlen(s+1),dp[maxn][2]={0};
	//dp[i][0]表示直接用钱支付这部分，dp[i][1]表示要找钱 
	s[0]='0';dp[len+1][1]=1;
	for(i=len;i>=0;i--)
	{
		int num=s[i]-'0';
		dp[i][0]=min(dp[i+1][0]+num,dp[i+1][1]+num+1);
		dp[i][1]=min(dp[i+1][0]+10-num,dp[i+1][1]+10-num-1);
	}
	printf("%d\n",min(dp[0][0],dp[0][1]));
}