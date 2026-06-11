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
using namespace std;
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
}
vector<ll>primess(ll n) {
	vector<ll>a;
	while (n % 2 == 0)n /= 2, a.push_back(2);
	ll sosuu = 3;
	while (n != 1) {
		if (n % sosuu == 0)n /= sosuu, a.push_back(sosuu);
		else if (sosuu > sqrt(n) + 2) {
			a.push_back(n);
			break;
		}
		else sosuu += 2;
	}
	return a;
}
signed main() {
	ll n; cin >> n;
	ll ans = 1000;
	vector<ll>a(n);
	rip(i, n)cin >> a[i];
	rip(i, n - 1) {
		if (a[i] < a[i + 1])ans += (a[i + 1] - a[i]) * (ans / a[i]);
	}
	cout << ans << endl;
}
