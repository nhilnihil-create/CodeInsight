#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e2 + 5;
const int lb = 60;
const int LB = lb + 5;

struct Linear_basis
{
	ll a[LB];
	int size;
	
	inline void init(void){ size=0; memset(a,0,sizeof(a));}
	
	bool insert(ll x)
	{
		for(int i=lb; i>=0 && x; --i)
		{
			if(!((x>>i)&1)) continue;
			if(a[i]){ x^=a[i]; continue;}
			
			for(int j=0; j<i; ++j)
				if((x>>j)&1) x^=a[j];
			for(int j=i+1; j<=lb; ++j)
				if((a[j]>>i)&1) a[j]^=x;
			a[i] = x;
			++size;
			
			return 1;
		}
		return 0;
	}
}lin;

ll a[MAXN];
char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	scanf("%s",s+1);
	
	lin.init();
	
	for(int i=n; i>=1; --i)
	{
		if(s[i]=='0') lin.insert(a[i]);
		else
		{
			if(lin.insert(a[i])){ printf("1\n"); return;}
		}
	}
	
	printf("0\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}