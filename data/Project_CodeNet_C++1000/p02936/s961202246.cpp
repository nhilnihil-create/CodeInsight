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
vector<int> v[2 * maxn];
vector<lli> counter;
void dfs(int node, int pre)
{
	if (pre != -1)
		counter[node] += counter[pre];
	for (auto i : v[node])
		if (i != pre)
			dfs(i, node);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0, q = 0, x = 0, y = 0, p = 0;
	cin >> n >> q;
	for (int i = 0; i + 1 < n; ++i)
	{
		cin >> x >> y; --x; --y;
		v[x].pb(y);
		v[y].pb(x);
	}
	counter.resize(n);
	counter.assign(n, 0);
	while (q--)
	{
		cin >> p >> x;
		--p;
		counter[p] += x;
	}
	dfs(0, -1);
	for (auto i : counter)
		cout << i << " ";
}