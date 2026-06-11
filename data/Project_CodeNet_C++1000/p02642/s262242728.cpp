#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], vis[maxn];
int n;
int ans;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%d", &a[i]);
		++vis[a[i]];
	}
	for(int i = maxn - 1; i >= 1; --i)
		if(vis[i])
		{
			if(vis[i] == 1)
			{
				for(int j = i + i; j < maxn; j += i)
					vis[j] = 0;
			}
			else
				for(int j = i; j < maxn; j += i)
					vis[j] = 0;
		}
	for(int i = 1; i <= n; ++i)
		ans += vis[a[i]];
	cout << ans << endl;
	return 0;
}
		
	 