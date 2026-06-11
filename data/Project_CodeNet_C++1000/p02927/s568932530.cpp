#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<time.h>
#include<sstream>
#define MINN -1e8 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF=0x3f3f3f3f3f3f;
const int P=1e9+7;
const int MAXN=32000;
const double pi=3.1415926;
//const int MINN=-1e8;
const ll mod=1000000007;

//map<string,ll> m;
//map<ll,ll> m;

//set<ll> s;

//vector<ll> v;

//scanf("%lld",&t);
int m,d,ans=0;
int main()
{
	cin>>m>>d;
	for(int i=2;i*10<=d;i++)
	{
		for(int j=2;j<10&&i*10+j<=d;j++)
		{
			if(i*j<=m)ans++;
			else break;
		}
	}
	cout<<ans;
	return 0;
}
//ll n,m,t,a,x,ans,res;
//ll powmod(ll a,ll b)     //快速幂 
//{
//	ll tmp=a%mod;
//	ll ans=1;
//	while(b)
//	{
//		if(b&1)ans=ans*tmp%mod;
//		tmp=tmp*tmp%mod;
//		b>>=1;
//	}
//	return ans%mod;
//}


//bool is_prime(ll a)     //判断素数 
//{
//	if(a==2)return 1;
//	else if(a==1||a%2==0)return 0;
//	else
//	{
//		for(ll i=3;i*i<=a;++i)
//		{
//			if(a%i==0)return 0;
//		}
//	}
//	return 1;
//}

