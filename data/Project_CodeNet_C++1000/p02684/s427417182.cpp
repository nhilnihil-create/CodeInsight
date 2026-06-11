#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n;
ll k;
int a[maxn], vis[maxn];
int main()
{
	scanf("%d%lld", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int i, j;
	memset(vis, -1, sizeof vis);
	for(i = 1, j = 0; vis[i] == -1; i = a[i], ++j)
	{
		vis[i] = j;
		if(j == k)
		{
			cout << i << endl;
			return 0;
		}
	}
	int c = j - vis[i];
	k = (k - vis[i]) % c;
	while(k)
	{
		--k;
		i = a[i];
	}
	cout << i << endl;
	return 0;
}
	
		