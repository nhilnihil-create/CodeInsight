#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)
// 最大公約数(ユークリッドの互除法)
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	ll A, B, C, D; cin >> A >> B >> C >> D;
	A--;
	ll tmp1 = B / C - A / C;
	ll tmp2 = B / D - A / D;
	ll t = C * D / gcd(C, D);
	ll tmp3 = B / t - A / t;
	A++;
	ll ans = (B - A + 1) - tmp1 - tmp2 + tmp3;
	cout << ans << endl;
}