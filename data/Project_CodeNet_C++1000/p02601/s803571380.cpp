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
	int a = 0, b = 0, c = 0, k = 0;
	cin >> a >> b >> c;
	cin >> k;
	int ct = 0;
	while (a >= b)
	{
		++ct; b *= 2;
	}
	while (b >= c)
	{
		++ct; c *= 2;
	}
	if (ct <= k)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
}