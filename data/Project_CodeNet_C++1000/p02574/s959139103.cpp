#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
#include<sstream>
#define x first
#define y second
#define lson u<<1
#define rson u<<1|1
#define pb push_back
#define pu pushup
#define mk make_pair
using namespace std;
#define ll long long
#define mod 1000000007
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int a[1000010];
bool cnt[1010000];
int prime[1010];
int cntt;
bool isprime(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
		return true;
}
int main()
{
	int n;
	cin>>n;
	int g=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],g=gcd(g,a[i]);
	for(int i=2;i<=1000;i++)
		if(isprime(i))
			prime[cntt++]=i;

	{
		bool flag=true;
		for(int i=1;i<=n;i++)
			{
			for(int j=0;j<cntt&&prime[j]*prime[j]<=a[i];j++)
					{
						int pj=prime[j];
						if(a[i]%pj==0)
						{
							if(cnt[pj])
							{
								flag=false;
								break;
							}
							cnt[pj]=true;
							while((a[i]%pj)==0)
								a[i]/=pj;
						}
						
						if(!flag)
							break;
					}
					if(a[i]!=1)
						{
							if(cnt[a[i]])
								flag=false;
							cnt[a[i]]=true;
						}
					if(!flag)
						break;
					}
		if(!flag && g==1)
			cout<<"setwise coprime"<<endl;
		else if(flag)
			cout<<"pairwise coprime"<<endl;
		else
			cout<<"not coprime"<<endl;
	}
}