#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn=1e5+10;
ll A[maxn],B[maxn],all;
int n;
vector<int> od;
bool less2(pii a,pii b)
{
	if(a.first!=b.first)return a.first>b.first;
	return a.second<b.second;
}
ll base[66];
void insert(ll val)
{
	for(int i=59;i>=0;i--)
	{
		if(val>>i&1)
		{
			if(!base[i])
			{
				base[i]=val;
				return;
			}
			val^=base[i];
		}
	}
}
ll getmax()
{
	ll res=0;
	for(int i=59;i>=0;i--)
	{
		if(!(res>>i&1))
		{
			res^=base[i];
		}
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
		all^=A[i];
	}
//	cout<<all<<endl;
	ll sum1=0;
	for(int i=0;i<60;i++)
	{
		if(!(all>>i&1))od.push_back(i);
		else sum1+=(1ll<<i);
	}
//	for(int i=0;i<od.size();i++)
//	{
//		cout<<od[i]; 
//	}
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<od.size();j++)
		{
			ll bit=(A[i]>>od[j])&1;
			B[i]|=(bit<<j);
		}
		insert(B[i]);
	}
	ll res=getmax();
	ll ans=0;
	for(int i=0;i<od.size();i++)
	{
		ll bit=(res>>i)&1;
		ans|=(bit<<od[i]);
	}
	printf("%lld\n",ans*2+sum1);
	return 0;
}