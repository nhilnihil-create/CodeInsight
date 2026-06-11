#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cmath>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <regex>
#include <random>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exout(x) printf("%.10f\n", x)
const double pi = acos(-1.0);
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX_N = 201010;

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

ll dx[4] = { 0,0,-1,1 };
ll dy[4] = { -1,1,0,0 };
ll num[30101][10];

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	rep(i, n) {
		ll res = s[i] - '0';
		num[i][res]++;
		rep(j, 10) {
			num[i + 1][j] += num[i][j];
		}
	}
	map<ll, ll>mp;
	for (ll i = 1;i < n - 1;++i) {
		rep(j, 10) {
			rep(k, 10) {
				ll res = s[i] - '0';
				res *= 10;
				if (num[i - 1][j] >= 1 && num[n - 1][k] - num[i][k] >= 1) {
					res += j * 100 + k;
					mp[res]++;
				}
			}
		}
	}
	ll ans = 0;
	for (auto p : mp) {
		ans++;
	}
	cout << ans << endl;
	return 0;
}
