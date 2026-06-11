#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <set>
#include <utility>
#include <climits>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>

#define ll long long
#define ull unsigned long long
using namespace std;

const int mod = 1e9 + 7;

ll fexp(ll base, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * base % mod;
		
		base = base * base % mod;
		p >>= 1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	ll cnt[k + 1]{};
	cnt[k] = 1;
	ll res = k;
	for (int i = k - 1; i > 0; --i) {
		cnt[i] = fexp(k / i, n);
		for (int j = 2 * i; j <= k; j += i) {
			cnt[i] -= cnt[j];
		}
		cnt[i] %= mod;
		res += cnt[i] * i;
	}
	cout << (res % mod + mod) % mod;
}