#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, k;
ll ans;
map<int, int> M;
ll norm(ll x) { return (x % k + k) % k;}
ll a[maxn];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]), a[i] += a[i - 1];
	M[0] = 1;
	for(int i = 1; i <= n; ++i) 
	{
		a[i] = norm(a[i] - i);
		if(i >= k) --M[a[i - k]]; 
		ans += M[a[i]];
		++M[a[i]];
	}
	printf("%lld\n", ans);
	return 0;
}