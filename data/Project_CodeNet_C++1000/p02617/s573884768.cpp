#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int main()
{
	int n;
	scanf("%d", &n);
	ans = 1ll * n * (n + 1) * (n + 2) / 6;
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		ans -= 1ll * u * (n - v + 1); 
	}
	cout << ans << endl;
	return 0;
}
		