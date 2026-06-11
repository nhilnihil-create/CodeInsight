#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a(m);
	rep(i, m) cin >> a[i];
	int s = 0;
	rep(i, m) s += a[i];
	if(s > n) printf("-1\n");
	else printf("%d\n", n - s);
	return 0;
}