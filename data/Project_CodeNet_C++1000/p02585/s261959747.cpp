#include<cstdio>
 
template<class I>
inline I max(I a, I b) {
	return a > b ? a : b;
}
 
long long _k, n, p[5010], c[5010], preans[5010], ed[5010], dis[5010], ans = -2147483647;
bool vis[5010];
 
long long getend(long long now, long long _from, long long _st) {
	if (!vis[now]) {
		vis[now] = 1;
		preans[now] = c[now] + preans[_from];
		long long t = getend(p[now], now, _st);
		ed[now] = t == -1  ? now : t,
		dis[now] = t == -1 ? 0 : dis[p[now]] + 1;
		return ed[now];
	}
	else
		return -1;
}
 
int main(void) {
	scanf("%lld%lld", & n, & _k);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", p + i);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", c + i);
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			ed[i] = getend(i, 0, i);
	for (int i = 1; i <= n; ++i) {
		long long tans = 0, k = _k, ttans = -2147483647, tttans = 0;
		if (dis[i] >= k) {
			long long now = i;
			for (int j = 1; j <= k; ++j)
				tans += c[now],
				ttans = max(ttans, tans),
				now = p[now];
		} else {
			long long now = i;
//			printf("%d\n", dis[now]);
			while (dis[now]) {
				tans += c[now],
				ttans = max(ttans, tans),
				now = p[now],
				--k;
				if (k == 0)
					goto A;
			}
			tans += c[now],
			ttans = max(ttans, tans),
			--k,
			tttans = tans;
			if (k / (dis[p[now]] + 1) > 0) {
				tans += preans[ed[i]] * (k / (dis[p[now]] + 1) - 1),
				k %= (dis[p[now]] + 1),
				k += dis[p[now]] + 1;
			} else {
				k %= (dis[p[now]] + 1);
			}
			tans = max(tans, tttans),
			now = p[now];
			if (!k)
				goto A;
			if (tans != tttans)
			for (int j = 1; j <= k; ++j)
				tans += c[now],
				ttans = max(ttans, tans),
				now = p[now];
			else while (dis[now]) {
				tans += c[now],
				ttans = max(ttans, tans),
				now = p[now],
				--k;
				if (k == 0)
					goto A;
			}
		}
A:
//		printf("%d\n", ttans);
		ans = max(ans, ttans);
	}
	printf("%lld\n", ans);
	return 0;
}
