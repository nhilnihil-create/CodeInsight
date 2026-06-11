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

int main()
{
	IOS;
	int N, M;
	cin >> N >> M;
	if (N % 2)
	{
		for (int i = 1; i <= M; ++i)
			cout << i << " " << (N - i) << endl;
	}
	else
	{
		int x = (M + 1) / 2;
		for (int i = 1; i <= x; ++i)
			cout << i << " " << (N - i + 1) << endl;
		for (int i = x+1; i <= M; ++i)
			cout << i << " " << (N - i) << endl;

	}
	return 0;
}