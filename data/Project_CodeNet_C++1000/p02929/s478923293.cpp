#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;
typedef string::const_iterator State;
class ParseError {};

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

constexpr ll INF = 1e16;
constexpr ll INM = 114514;
constexpr ll MOD = 1e9 + 7;
constexpr ld EPS = 1e-12;

template <typename T>
void dump(T x) { cout << x << endl; }
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
inline ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
}
ll powm(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		ll d = powm(a, b / 2, c);
		return (d * d) % c;
	} else
		return (a * powm(a, b - 1, c)) % c;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

int main() {
	IOS();
	ll n;
	string s;
	cin >> n >> s;
	vector<bool> d(2 * n);
	ll left = 0, right = 0;
	for (int i = 0; i < 2 * n; i++) {
		d[i] = s[i] == 'W';
		if (i % 2 == 0) d[i] = !d[i];
		if(d[i]){
			left++;
		}else {
			right++;
		}
	}
	if(left != right){
		dump(0);
		return 0;
	}
	ll ans = 1;
	ll cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (d[i])
			cnt++;
		else {
			ans *= cnt;
			cnt--;
		}
		if(cnt < 0){
			dump(0);
			return 0;
		}
		ans %= MOD;
	}
	for (int i = 1; i <= n; i++) {
		ans *= i;
		ans %= MOD;
	}
	dump(ans);

	return 0;
}