#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 2e5 + 5;
int a[N], b[N];
priority_queue<pair<int, int> > Q;

int main()
{
	int n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) b[i] = read(), Q.push({b[i], i});
	
	long long ans = 0;
	while (!Q.empty())
	{
		int i = Q.top().second;
		Q.pop();
		if (b[i] == a[i]) continue;
		
		int pre = i == 1 ? n : i - 1;
		int nxt = i == n ? 1 : i + 1;
		if (b[i] - b[pre] - b[nxt] < a[i]) return puts("-1"), 0;
		
		ans += (b[i] - a[i]) / (b[pre] + b[nxt]);
		b[i] = a[i] + (b[i] - a[i]) % (b[pre] + b[nxt]);
		if (a[i] != b[i]) Q.push({b[i], i});
	}
	printf("%lld\n", ans);
	return 0;
}
