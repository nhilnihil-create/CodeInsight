#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull; 
typedef long double ld;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const double eps = 1e-10;
const ll inf = 1e18;
const int maxn = 200005;
inline ll read() { ll s = 0, w = 1; char ch = getchar(); for (; !isdigit(ch); ch = getchar()) if (ch == '-') w = -1; for (; isdigit(ch); ch = getchar())    s = (s << 1) + (s << 3) + (ch ^ 48); return s * w; }
inline void write(ll x) { if (!x) { putchar('0'); return; } char F[40]; ll tmp = x > 0 ? x : -x; if (x < 0)putchar('-');    int cnt = 0;    while (tmp > 0) { F[cnt++] = tmp % 10 + '0';        tmp /= 10; }    while (cnt > 0)putchar(F[--cnt]); }
inline ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll qpow(ll a, ll b) { ll ans = 1;    while (b) { if (b & 1)    ans *= a;        b >>= 1;        a *= a; }    return ans; }    ll qpow(ll a, ll b, ll mod) { ll ans = 1; while (b) { if (b & 1)(ans *= a) %= mod; b >>= 1; (a *= a) %= mod; }return ans % mod; }
inline int lowbit(int x) { return x & (-x); }

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	if (s[2] == s[3] && s[4] == s[5])
	{
		cout << "Yes";
	}
	else
		cout << "No";
	return 0;
}