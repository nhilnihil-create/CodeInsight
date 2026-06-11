#include<bits/stdc++.h>
#include<numeric>
#include<cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#define ll long long int
#define CON 100010
const long long mod=1e9+7;
const int INF=1001001001;
const int inf=100000;
//const ll inf=1e9+7;
//const ll ful=1e18;
using namespace std;
//namespace mp = boost::multiprecision;
int main() 
{
	int n;
	cin>>n;
	vector<int> b(n-1);
	vector<int> a(n);
	for(int i=0;i<n-1;++i)
	{
		cin>>b[i];
	}
	a[0]=b[0];
	a[n-1]=b[n-2];
	ll ans=a[0]+a[n-1];
	for(int i=1;i<n-1;++i)
	{
		a[i]=min(b[i-1],b[i]);
		ans+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}