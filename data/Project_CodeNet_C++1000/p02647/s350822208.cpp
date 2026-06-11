#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,k,a[maxn],d[maxn];
int main() {
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	while (k--)	{
		bool f = true;
		for (int i = 1; i <= n; i++)
			if (a[i] != n) f = false;
		if (f) break;
		for (int i = 0; i <= n + 1; i++)
			d[i] = 0;
		for (int i = 1; i <= n; i++) {
			int l = max(i - a[i],1), r = min(i + a[i],n);
			d[l]++,d[r + 1]--;
		}
		for (int i = 1; i <= n; i++)
			d[i] += d[i - 1];
		for (int i = 1; i <= n; i++)
			a[i] = d[i];
	}
	for (int i = 1; i <= n; i++)
		printf("%d%s",a[i],i == n ? "\n" : " ");
	return 0;
}