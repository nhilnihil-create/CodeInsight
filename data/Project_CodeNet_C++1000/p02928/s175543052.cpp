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
const ll mod = 1000000007;
int main() {
	ll N, K, t = 0, x = 0;
	ll ans = 0;
	cin >> N >> K;
	vector<int> A(N);
	rep(i, 0, N)cin >> A[i];
	rep(i, 0, N) {
		rep(i2, i + 1, N) {
			if (A[i] > A[i2])t++;
		}
		t %= mod;
	}
	ans += t * K;
	ans %= mod;
	t = 0;
	rep(i, 0, N) {
		rep(i2, 0, N) {
			if (A[i] < A[i2])t++;
		}
		t %= mod;
	}
	ans += t * ((K * (K - 1) / 2) % mod) % mod;
	ans %= mod;
	printf("%lld\n", ans);
	return 0;
}