#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int fpw(int a, int b)
{
	int ans = 1;
	while(b)
	{
		if(b&1) ans = 1ll*ans*a%mod;
		a = 1ll*a*a%mod;
		b >>= 1;
	}
	return ans;
}
int main()
{
	int n; scanf("%d", &n);
	int ans = ((fpw(10, n) - 2*fpw(9, n))%mod + fpw(8, n))%mod;
	if(ans<0) ans += mod;
	printf("%d\n", ans);
	return 0;
}