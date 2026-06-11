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


ll e_sum(vll&e, int k, int n)
{
	if(n<1) return 0;
	ll ret=e[k]*((n-1)/k);
	ret+=e[(n-1)%k];
	return ret;
}


void dump(vll&v, const char *pre="")
{
	printf("%s", pre);
	for(auto m:v) printf("%lld ", m);
	printf("\n");
}


int solve(int n, int x, int m, vi&d, int k)
{
	vll e(k+1), z(k+1), c(k+1);

	for(int i=0;i<k;i++)
	{
		e[i+1]=e[i]+d[i]%m;
		z[i+1]=z[i]+(d[i]%m==0);
		c[i+1]=c[i]+e[i+1]/m;
		e[i+1]%=m;
	}

	static bool is_first=true;
	if(0)
	{
		is_first=false;
	dump(e, "e=");
	dump(z, "z=");
	dump(c, "c=");
	}

	ll s=x%m+e_sum(e, k, n);
	ll ret=n-1-s/m;
	ret-=e_sum(c, k, n);
	ret-=e_sum(z, k, n);

//	printf("n=%d  s=%lld  cn=%lld  zn=%lld\n", n, s, e_sum(c, k, n), e_sum(z, k, n));

	return ret;
}


int main(void)
{
	int k, q;
	while(scanf("%d%d", &k, &q)==2)
	{
		vi d(k);
		for(auto&m:d) scanf("%d", &m);

		vi n(q), x(q), m(q);
		for(int i=0;i<q;i++)
		{
			scanf("%d%d%d", &n[i], &x[i], &m[i]);
		}

		for(int i=0;i<q;i++)
		{
			printf("%d\n", solve(n[i], x[i], m[i], d, k));
		}
	}
	return 0;
}
