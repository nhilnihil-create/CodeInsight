/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using lli = long long int;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int MOD = 1000000007;
const int MOD1 = 998244353;
const int maxn = 100010;
const int lim = (int)1e9;
/*__int128 read()
{
	__int128 ans = 0;
	int sgn = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-')
			sgn *= -1;
		c = getchar();
	}
	while (isdigit(c))
	{
		ans = ans * 10 + c - '0';
		c = getchar();
	}
	return ans * sgn;
}
void print(__int128 x)
{
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, q = 0, ch = 0, p = 0, l = 0, r = 0; lli x = 0ll;
	cin >> n >> q;
	fenwick_tree<lli> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> x; v.add(i, x);
	}
	for (int i = 0; i < q; ++i)
	{
		cin >> ch;
		if (ch == 0)
		{
			cin >> p >> x; v.add(p, x);
		}
		else
		{
			cin >> l >> r; cout << v.sum(l, r) << "\n";
		}
	}
}