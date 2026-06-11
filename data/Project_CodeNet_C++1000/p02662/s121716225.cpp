#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 10;
typedef long long ll;
const ll mod = 998244353;
int n, s;
ll f[maxn];
int main()
{
	scanf("%d%d", &n, &s);
	f[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		int val;
		scanf("%d", &val); 
		for(int j = s; ~j; --j)
		{
			f[j] = f[j] * 2 % mod;
			if(j >= val)
				f[j] = (f[j] + f[j - val]) % mod;
		}
	}
	cout << f[s] << endl;
	return 0;
}
			
	
	 