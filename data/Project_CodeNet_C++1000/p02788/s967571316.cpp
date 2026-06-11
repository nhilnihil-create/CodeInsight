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

int main(void)
{
	int n, d, a;
	while(scanf("%d%d%d", &n, &d, &a)==3)
	{
		vpii xh(n);
		for(auto&m:xh)
		{
			scanf("%d%d", &m.first, &m.second);
			m.second=(m.second+a-1)/a;
		}

		sort(xh.begin(), xh.end());
		ll ans=0;
		int atk=0;

		deque<pair<ll,int> > re;

		for(int s=0;s<n;s++)
		{
			for(;!re.empty();)
			{
				if(re.front().first>=xh[s].first) break;
				atk-=re.front().second;
				re.pop_front();
			}
			xh[s].second-=atk;
			if(xh[s].second<=0) continue;
			ans+=xh[s].second;
			atk+=xh[s].second;
			re.push_back(make_pair(xh[s].first+2LL*d, xh[s].second));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
