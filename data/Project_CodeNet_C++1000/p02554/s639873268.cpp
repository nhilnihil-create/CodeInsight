#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll pow(ll x, ll y)
{
	ll res = 1;
	while(y)
	{
		if(y&1)	
			res = res*x%mod;
		x = x*x%mod;
		y=y>>1;
	}
	return res;
}
int main()
{
	ll n;
	cin>>n;
	pow(10ll,n)-2*pow(9ll,n)+pow(8ll,n);
	cout<<((pow(10ll,n)-2*pow(9ll,n)+pow(8ll,n))%mod+mod)%mod<<endl;
	return 0;
}