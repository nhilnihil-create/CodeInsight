#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int N = 20005;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, idx;
long long ans, x, k, d, p[N], c[N], s[N];
long long q[N];
bool st[N];

int main()
{
	scanf("%d %lld", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%lld", &p[i]);
	for(int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
	ans = -INF;
	for(int i = 1; i <= n; ++i)
	{
		if(!st[i])
		{
			int r = 0;
			long long maxv = -INF;
			idx = 1;
			s[0] = 0;
			while(!st[i])
			{
				s[idx] = s[idx-1] + c[i];
				++idx;
				st[i] = true;
				i = p[i];
			}
			if(s[--idx] > 0)
			{
				r = k % idx;
				if(!r) r = idx;
			}
			else r = min(idx, int(k));
			for(int i = 1; i <= idx; ++i) s[i + idx] = s[i] + s[idx];
			int hh = 0, tt = -1;
			for(int i = 0; i < idx << 1; ++i)
			{
				while(hh <= tt && s[q[tt]] >= s[i]) --tt;
				q[++tt] = i;
				if(q[hh] <= i - r) ++hh;
				maxv = max(maxv, s[i + 1] - s[q[hh]]);
			}
			if(s[idx] > 0) maxv += s[idx] * ((k - 1) / idx);
			ans = max(ans, maxv);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
