/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
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
	lli l = 0ll, r = 0ll;
	cin >> l >> r;
	if (r - l > 3000)
		cout << "0" << endl;
	else
	{
		lli res = 2018;
		for (lli i = l; i < r; ++i)
			for (lli j = i + 1; j <= r; ++j)
				res = min(res, (1ll * i * j) % 2019);
		cout << res << endl;
	}
}