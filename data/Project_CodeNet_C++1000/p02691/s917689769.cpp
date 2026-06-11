#include<bits/stdc++.h>
//#include <iostream>
//#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
template<typename T>T gcd(T a,T b){if(b==0)return a;else return gcd(b,a%b);}
template<typename T>T lcm(T a,T b){return a/gcd(a,b)*b;}
template<typename T>T maxx(T a,T b){if(a>=b) return a;else return b;}
template<typename T>T minn(T a,T b){if(a<=b) return a;else return b;}
ll power(ll x,ll y,ll p){ll res=1;x%=p;while(y>0){if(y&1)res=((res%p)*(x%p))%p;y>>=1;x=(x*x)%p;}return res;}
ll powerfew(ll x,ll y){ll res=1;while(y>0){if(y&1)res*=x;y>>=1;x*=x;}return res;}
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define loop(i,n) for(int i=1;i<=n;++i)
#define mem(x,y) memset(x,y,sizeof(x))
#define PI  3.141592653589
#define INF 0x3f3f3f3f//(1061109567)
const ll MAX=2e5+10;
ll a[1000000],b[1000000],c[1000000];
int main()
{
	ll n;
	cin >>n;
	for(ll i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		if((i+a[i])<=n)//sadasdasd
		{
			b[i+a[i]]++;
		}
	}
	for(ll i=1;i<=n;i++)
	{
		if((i-a[i])>0)
		{
			c[i-a[i]]++;
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ans+=c[i]*b[i];
	}
	cout <<ans<<endl;
	return 0;
}