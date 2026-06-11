#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iostream>
#include <bitset>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
//ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll c(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }
int main(void) {
	char s[100001], t[100001];
	int len, ls;
	ll ans = 0;
	scanf("%s%s", s, t);
	ls = strlen(s);
	len = strlen(t);
	map<char, int> mp;
	rep(i, 0, ls)mp[s[i]]++;
	rep(i, 0, len) {
		if (mp[t[i]] == 0) {
			puts("-1");
			return 0;
		}
	}
	vector<vector<int>> np(ls, vector<int>(26));
	int v;
	char* next;
	rep(i, 0, ls) {
		rep(i2, 0, 26) {
			if (mp[i2 + 'a'] == 0)continue;
			if (i == 0 || i && np[i - 1][i2] <= 1) {
				v = 1;
				next = s + i;
				while (*next != i2 + 'a') {
					next++;
					v++;
					if (next == s + ls)next = s;
					if (v >= ls)break;
				}
				np[i][i2] = v;
			}
			else np[i][i2] = np[i - 1][i2] - 1;
		}
	}
	rep(i, 0, len) {
		ans += (ll)np[ans % ls][t[i] - 'a'];
	}
	printf("%lld\n", ans);
	return 0;
}
