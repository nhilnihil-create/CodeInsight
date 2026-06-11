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

int align(int offset, int x, int p)
{
	int ret=(offset+x)%p;
	if(ret<0) ret+=p;
	return ret;
}

int main(void)
{
	int n, p;
	char s[200000+2];
	while(scanf("%d%d\n%200000[0-9]\n", &n, &p, s)==3)
	{
		ll ans=0;
		if(p==2 || p==5)
		{
			for(int i=0;i<n;i++)
			{
				int x=s[i]-'0';
				if(x%p==0) ans+=i+1;
			}
			printf("%lld\n", ans);
			continue;
		}

		vi dp(p);
		int u=1;
		int v=0;
		dp[0]=1;
		for(int i=0;i<n;i++)
		{
			int x=(s[n-1-i]-'0')%p;
			v=(v+u*x)%p;
			ans+=dp[v];
			dp[v]++;
			u=(u*10)%p;
		}

		printf("%lld\n", ans);
	}
	return 0;
}
