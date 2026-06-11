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

ll dx[8] = { 1,-1,0,0,1,1,-1,-1 };
ll dy[8] = { 0,0,1,-1,1,-1,1,-1 };
string dir[8] = { "R","L","D","U","RD","RU","LD","LU" };
bool flag[201010];
ll ans[201010];

vector<vector<ll>>to;

void dfs(ll v) {
	flag[v] = true;
	for (auto nv : to[v]) {
		if (flag[nv] == false) {
			ans[nv] += ans[v];
			dfs(nv);
		}
	}
}

//long longしか使わない
//素数は1より大きい
//lower_boundは指定したkey以上の要素の一番左のイテレータをかえす
//upper_boundは指定したkeyより大きい要素の一番左のイテレータをかえす
int main() {
	ll n, q;
	cin >> n >> q;
	to.resize(n);
	rep(i, n-1) {
		ll a, b;
		cin >> a >> b;
		a--, b--;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	rep(i, q) {
		ll p, x;
		cin >> p >> x;
		p--;
		ans[p] += x;
	}
	dfs(0);
	rep(i, n) {
		cout << ans[i];
		cout << " ";
	}
	cout << endl;
	return 0;
}
