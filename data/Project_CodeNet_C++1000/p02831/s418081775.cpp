#include<bits/stdc++.h>
#include<numeric>
#include<cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#define ll long long int
#define CON 100010
const long long mod=1e9+7;
const int INF=1001001001;
//const int inf=100000;
//const ll ful=1e18;
using namespace std;
//namespace mp = boost::multiprecision;
ll gcd(ll a,ll b)
{
	ll r=a%b;
	if(r==0)
	{
		return b;
	}
	return gcd(b,r);
}
ll lcm(ll num,ll gcd)
{
	return num/gcd;
}
int main() 
{
	ll a,b;
	cin>>a>>b;
	ll com=a*b;
	ll mul=gcd(max(a,b),min(a,b));
	ll ans=lcm(com,mul);
	cout<<ans<<endl;
	return 0;
}