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
int main() {
	ll n, k, x = 0, y = 0;

	cin >> n >> k;
	vector<int> a(n);
	rep(i, 0, n)cin >> a[i];
	rep(i, 0, n - 1) {
		rep(i2, i + 1, n)if (a[i] > a[i2])x++;
	}
	rep(i, 0, n){
		rep(i2, 0, n) {
			if (a[i] > a[i2])y++;
		}
	}
	printf("%lld\n", ((y * ((k - 1) * k / 2 % mod)) % mod + x * k % mod) % mod);
	return 0;
}
