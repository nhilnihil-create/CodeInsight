#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vpii=vector<pii>;

#define PI 3.1415926535897932384626433832795


ll gcd(ll a, ll b)
{
	ll c;

	while((c=a%b))
	{
		a=b;
		b=c;
	}
	return b;
}


ll lcm(ll a, ll b)
{
	return a/gcd(a, b)*b;
}


int lsb(int v)
{
	for(int i=0;v;i++)
	{
		if((v>>i)&1) return i;
	}
	return 0;
}


int solve(vi&a, int m)
{
	int b=lsb(a[0]);
	for(int ma:a)
	{
		if(b!=lsb(ma)) return 0;
	}

	ll x=1;
	for(int ma:a)
	{
		x=lcm(x, ma/2);
		if(x>m) break;
	}
	return (m/x+1)/2;
}


int main(void)
{
	int n, m;
	while(scanf("%d%d", &n, &m)==2)
	{
		vi a(n);

		for(auto&ma:a) scanf("%d", &ma);
		printf("%d\n", solve(a, m));
	}
	return 0;
}
