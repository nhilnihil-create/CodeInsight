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
const ll cs=1000000000;
//15
bool z[1000]={};

int main()
{
 int N;
 string s;
 scanf("%d",&N); cin>>s;
 bool dig1[10]={};
 for(int i=0;i<(N-2);i++)
 {
	int d1=s[i]-'0';
	if(!dig1[d1])
	{
		dig1[d1]=true;
		bool dig2[10]={};
		for(int j=i+1;j<(N-1);j++)
		{
			int d2=s[j]-'0';
			if(!dig2[d2])
			{
				dig2[d2]=true;
				for(int k=j+1;k<N;k++)
				{
					int d3=s[k]-'0';
					int d=d1*100+d2*10+d3;
					z[d]=true;
				}
			}
		}
	}
 }
 int ans=0;
 for(int i=0;i<1000;i++)
 {
	if(z[i]){ans++;}
 }
 printf("%d",ans);
}