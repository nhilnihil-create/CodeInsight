#include <bits/stdc++.h>

using namespace std;

const int N = 300000 + 5;

int n, cnt[N], sum[N], tcnt[N];

inline int check (int l, int k)
{
	return ( (cnt[n] - cnt[k]) * k + sum[k] ) >=  l * k;
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int x; scanf ("%d", &x);
		tcnt[x]++;
	}
	for (int i = 1; i <= n; ++i) sum[ tcnt[i] ] += tcnt[i], cnt[ tcnt[i] ] ++;
	for (int i = 1; i <= n + 1; ++i) cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];
	int now = n + 1;
	for (int i = 1; i <= n; ++i)//bottom length
	{
		while (now && !check(i, now)) now--;
		printf ("%d\n", now);
	}
	return 0;
}


































