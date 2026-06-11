#include <boost/multiprecision/cpp_int.hpp>
#define ll long long int
#define CON 100010
const long long mod=1e9+7;
const int INF=1001001001;
//const ll inf=1e9+7;
//const ll ful=1e18;
using namespace std;

//namespace mp = boost::multiprecision;
int main() 
{
	ll l,r;
	cin>>l>>r;
	r=min(r,l+4038);
	ll ans=2018;
	for(ll i=l;i<=r;i++)
	{
		for(ll j=i+1;j<=r;j++)
		{
			ll now=(i*j)%2019;
			ans=min(ans,now);
		}
	}
	cout<<ans<<endl;
	return 0;
}
