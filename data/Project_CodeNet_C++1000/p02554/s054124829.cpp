#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
// #include <cmath>
// #include <map>
// #include <set>
// #include <deque>
// #include <stack>
// #include <vector>
using namespace std;
#define debug freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// #define PI acos(-1)
typedef long long ll;
const ll mod=1e9+7;


ll mypow(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1; 
	}
	return ans;
}

int main()
{
	//debug;
	ios;
	ll a;
	cin>>a;
	cout<<((mypow(10,a)+mod+mypow(8,a)+mod-mypow(9,a)*2)%mod+mod)%mod;
	return 0;
}