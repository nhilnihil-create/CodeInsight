#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<cmath>
//#include<algorithm>
//#define debug1 cout<<"?"<<endl;
//#define debug2 cout<<"?"<<i<<endl;
#define PII pair<int,int>
typedef long long ll;
const int maxn=3e5+9;
const double pi=acos(-1);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double ep=1e-7;
using namespace std;
int main()
{
	ll k,q,i,d[maxn]={0};
	scanf("%lld%lld",&k,&q);
	for(i=0;i<k;i++)scanf("%lld",&d[i]);
	while(q--)
	{
		ll n,a,m,b[maxn]={0},sum=0;
		scanf("%lld%lld%lld",&n,&a,&m);
		a%=m;n--;
		for(i=0;i<k;i++)b[i]=d[i]%m,sum+=b[i];
		ll tot=0;//1-n有多少个数c[i]为0 
		for(i=0;i<k;i++)if(!b[i])tot+=(n/k)+(i<n%k); 
		ll an=sum*(n/k)+a;
		for(i=0;i<n%k;i++)an+=b[i];
		tot+=an/m;
		printf("%lld\n",n-tot);
	}
}