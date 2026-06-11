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
	int n = 0, m = 0, a = 0, b = 0; lli res = 0ll;
	cin >> n >> m;
	vector<vector<int> > v(m);
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		if (a <= m)
			v[m - a].pb(b);
	}
	priority_queue<int> pq;
	for (int i = m - 1; i >= 0; --i)
	{
		for (auto j : v[i])
			pq.push(j);
		if (!pq.empty())
		{
			res += pq.top(); pq.pop();
		}
	}
	cout << res << endl;
}