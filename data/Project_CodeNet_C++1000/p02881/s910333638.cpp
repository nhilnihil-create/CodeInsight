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
int main() 
{
	ll n;
	cin>>n;
	ll rep=sqrt(n);
	vector<ll> a;
	for(ll i=1;i<=rep;++i)
	{
		if(n%i==0)
		{
			ll ans=n/i+i-2;
			a.push_back(ans);
		}
	}
	sort(a.begin(),a.end());
	cout<<a[0]<<endl;
	return 0;
}