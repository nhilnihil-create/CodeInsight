#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<iomanip>
#include<numeric>
#include<queue>
#include<deque>
#include<cfloat>
#include<functional>
#include<tuple>
#include<math.h>
#include<bitset>
#include<stack>
#include<set>
#include<random>
#include<stdlib.h>
#define rip(i,n) for(int i=0;i<n;i++)
#define Rip(i,n) for(int i=1;i<=n;i++)
#define RIP(i,a,b) for(int i=a;i<b;i++)
#define all(V) V.begin(),V.end()
#define sec  setprecision;
#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx")
#pragma optimize("O3")
#pragma optimize("unroll-loops");
constexpr double eps = 1e-9;
constexpr double pi = 3.141592653589793238462643383279;
using ll = long long;
using ld = long double;
using Pa = std::pair<ll, ll>;
ll MOD = 998244353;
ll gcd(ll a, ll b)
{
	if (a % b == 0)	return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
ll pow(ll x, ll n, ll mod) {
	x %= mod;
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return (pow((x * x) % mod, n / 2, mod) % mod);
	else
		return (x * pow(x, n - 1, mod) % mod);
}ll zero = 0;
using namespace std;
signed main() {
	int n; cin >> n;
	vector<int>a(n);
	rip(i, n)cin >> a[i];
	ll sum = 0;
	rip(i, n)sum += a[i];
	vector<int>ans(n);
	ll sumsum = 0;
	rip(i, n)if (i % 2 == 1)sumsum += 2 * (long long)a[i];
	ans[0] = sum - sumsum;
	for (int i = 1; i < n; i++) {
		ans[i] = 2 * a[i - 1] - ans[i-1];
	}
	rip(i, n)cout << ans[i] << endl;
}
