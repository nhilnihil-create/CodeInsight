#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
//No change above here

const ll maxi = (2 * 1e6 + 3);
ll mod = (1e9 + 7);

//function for power
ll power(ll x, ll n) {
	ll res = 1;
	x %= mod;
	while (n) {
		if (n & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}

ll dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

ll p, q;
bool valid(ll i, ll j) { return i >= 1 && i <= p && j >= 1 && j <= q; }

//declare needed things here
ll N, M, Q;
int a[52], b[52], c[52],d[52];
ll ans;
vector<int> v{0};
void dfs(int len, int cur)
{
	if (len == N)
	{
		ll temp = 0;
		for (int i = 1; i <= Q; ++i)
		{
			if (v[b[i]] - v[a[i]] == c[i])
				temp += d[i];
		}
		ans = max(ans, temp);
		return;
	}
	for (int i = cur; i <= M; ++i)
	{
		v.push_back(i);
		dfs(len + 1, i);
		v.pop_back();
	}

}
int main()
{
	IOS;
	cin >> N >> M >> Q;
	for (int i = 1; i <= Q; ++i)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	ans = 0;
	dfs(0, 1);
	cout << ans << endl;
	return 0;
}