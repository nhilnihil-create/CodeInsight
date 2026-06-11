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
#include<functional>
#include<tuple>
#include<math.h>
#include<bitset>
#include<stack>
#include<set>
#define rip(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ld long double
#define pi 3.1415926535897932384626433832795028841971693993
#define MOD 998244353
#define sec setprecision
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
	if (n == 0)
		return 1;
	else if (x == 1)return(1);
	else if (n % 2 == 0)
		return pow(x * x, (n / 2));
	else
		return x * pow(x, n - 1);
}
int ketasuu(ll h) {
	if (h < 0)return(-(ketasuu(-h)));
	else if (h < 10)return(1);
	else return(1 + ketasuu(h / 10));
}
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
void cominit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long com(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	ll a;
	cin >> a;
	string b;
	cin >> b;
	a*=100*(b[0]-'0')+10*(b[2]-'0')+(b[3]-'0');
	cout << a/100 << endl;
}
