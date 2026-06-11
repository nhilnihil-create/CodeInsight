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
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const ll mod = 998244353;
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
int main() {
	ll N, M = 0, t;
	cin >> N;
	vector<int> K(N);
	cin >> t;
	if (t == 0) {
		rep(i, 1, N)cin >> t, K[t]++, M = max(M, t);
		if (K[0] == 0) {
			t = K[0] = 1;
			rep(i, 1, M + 1) {
				t *= (ll)mpower(K[i - 1], K[i]);
				t %= mod;
			}
			printf("%lld\n", t);
			return 0;
		}
	}
	puts("0");
	return 0;
}
