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
#define rip(i,n) for(ll i=0;i<n;i++)
#define Rip(i,n) for(ll i=1;i<=n;i++)
#define all(V) V.begin(),V.end()
#define ll long long
#define ld long double
#define MOD 1000000007
#define mod 998244353
#define sec setprecision
#define Pair pair<ll,ll>
#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx")
#pragma optimize("O3")
#pragma optimize("unroll-loops")
constexpr double eps = 1e-9;
constexpr double pi = 3.141592653589793238462643383279;
using namespace std;
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
int main() {
	int n, m; cin >> n >> m;
	vector<int>a(m); rip(i, m)cin >> a[i];
	vector<int>dp(n+1,0);//dp[i]deidannmeniikutoori
	dp[0] = 1;
	rip(i, m)dp[a[i]] = 0;
	vector<bool>pd(n + 1, true);
	rip(i, m)pd[a[i]] = false;
	for (int i = 1; i <= n; i++) {
		if (pd[i] == true) {
			if (i == 1)dp[i] = 1;
			else dp[i] = (dp[i - 1]%MOD + dp[i - 2]%MOD);
		}
	}
	cout << dp[n]%MOD << endl;
}
