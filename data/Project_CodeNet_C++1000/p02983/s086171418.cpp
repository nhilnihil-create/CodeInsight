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
#define int long long
#pragma target("avx")
#pragma optimize("O3")
#pragma optimize("unroll-loops");
constexpr double eps = 1e-9;
constexpr double pi = 3.141592653589793238462643383279;
using namespace std;
using ll = long long;
using ld = long double;
using Pa = pair<int, int>;
ll mod = 1000000007;
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
ll pow(ll x, ll n) {
	x %= mod;
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return (pow((x * x) % mod, n / 2) % mod);
	else
		return (x * pow(x, n - 1)) % mod;
}
signed main() {
	int l, r; cin >> l >> r;
	int k = (l + 1) / 2019;
	int m = (r + 1) / 2019;
	if (m > k)cout << 0 << endl;
	else {
		l %= 2019;
		r %= 2019;
		int ans = 2019;
		for (int i = l; i <= r; i++) {
			for (int j =i+1; j <= r; j++) {
				ans = min(ans,j*i%2019 );

			}
		}
		cout << ans << endl;
	}
}