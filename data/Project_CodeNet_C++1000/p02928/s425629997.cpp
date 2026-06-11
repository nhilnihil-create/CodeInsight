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
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
//ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
int main() {
	ll N, K, t = 0, t2 = 0;
	cin >> N >> K;
	vector<int> a(N);
	rep(i, 0, N)cin >> a[i];
	rep(i, 0, N)rep(i2, i + 1, N)if (a[i] > a[i2])t++;
	rep(i, 0, N)rep(i2, 0, N)if (a[i] > a[i2])t2++;
	printf("%lld\n", (t * K % mod + (K - 1) * K / 2 % mod * t2 % mod) % mod);
	return 0;
}
