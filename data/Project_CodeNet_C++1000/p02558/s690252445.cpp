/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
#include<atcoder/dsu>
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, q = 0, ch = 0, x = 0, y = 0;
	cin >> n >> q;
	dsu v(n);
	for (int i = 0; i < q; ++i)
	{
		cin >> ch >> x >> y;
		if (ch == 0)
			v.merge(x, y);
		else
		{
			if (v.same(x, y))
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}