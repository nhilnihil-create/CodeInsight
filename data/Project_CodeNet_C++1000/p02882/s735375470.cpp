#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
typedef pair<int, int>P;
typedef long long ll;
#define rep(i,n)for(ll i=0;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll MOD = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 5000100;
//max=({});
//条件式が真ならwhileの中身を回し続ける
//printf("%d\n", ans);

//pairの入力
//vector<pair<ll, ll>>work(n);
//rep(i, n) {
//	ll a, b;
//	cin >> a >> b;
//	work[i] = make_pair(a, b);
//for(auto p:mp)(mapの探索)
//printf("%.10f\n",なんちゃら)
//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

//組み合わせの余りを求める
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(ll n,ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll dx[8] = { 0,0,-1,1 };
ll dy[8] = { -1,1,0,0 };
ll dp[101010];

//long longしか使わない
//素数は1より大きい
int main() {
	double a, b, x;
	cin >> a >> b >> x;
	double h = x / (a * a);
	double ans;
	if (2*h >= b) {
		double res = 2 * b / a - 2 * x / (a * a * a);
		ans = atan(res);
	}
	else {
		double res = a * b * b / (2 * x);
		ans = atan(res);
	}
	ans *= 180;
	ans /= M_PI;
	exout(ans);
	return 0;
}
