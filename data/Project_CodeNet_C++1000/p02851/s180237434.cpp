#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stack>
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll; 
map<ll, ll> mp;
ll d[200005];
ll x, n, k, a, s, ans;
int main()
{
	while (~scanf("%lld%lld", &n, &k))
	{
		ans = s = 0;
		mp.clear();
		mp[0] = 1;
		for (ll i = 1; i <= n; i++)
		{
			if (i - k >= 0)
				mp[d[i - k]]--;
			scanf("%lld", &a);
			s += a;
			x = (s - i) % k;
			ans += mp[x];
			mp[x]++;
			d[i] = x;
		}
		printf("%lld\n", ans);
	}
}