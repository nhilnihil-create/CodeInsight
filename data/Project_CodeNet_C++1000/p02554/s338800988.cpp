#include<iostream>
#include<algorithm>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll N;

ll qsm(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ans;
}

int main()
{
	ios;
	cin>>N;
	cout<<((qsm(10,N)-2*qsm(9,N)+qsm(8,N))%MOD+MOD)%MOD<<"\n";
	return 0;
}