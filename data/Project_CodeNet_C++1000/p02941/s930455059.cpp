#include <bits/stdc++.h>
using namespace std;
#define mp(a, b) make_pair(a, b)
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
int n;
int a[maxn], b[maxn];
typedef long long ll;
ll ans;
priority_queue<pii> Q;
inline int pre(int x) { return x == 1 ? n : x - 1;}
inline int nxt(int x) { return x == n ? 1 : x + 1;}
void no() { puts("-1"); exit(0);}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%d", &b[i]); 
		if(b[i] > a[i]) Q.emplace(b[i], i);
		if(b[i] < a[i]) no();
	}
	while(!Q.empty())
	{
		pii x = Q.top(); Q.pop();
		int i = x.second;
		int sum = b[pre(i)] + b[nxt(i)];
		if(b[i] < sum) no();
		if((b[i] - a[i]) % sum == 0)
		{
			ans += (b[i] - a[i]) / sum;
			b[i] = a[i];
			continue;
		}
		int step = b[i] / sum;
		b[i] -= step * sum;
		ans += step;
		if(b[i] < a[i]) no();
		Q.emplace(b[i], i);
	}
	printf("%lld\n", ans);
	return 0;
}
			
	
	