#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000LL;
constexpr auto MOD = 1000000007;

ll gcd(ll i, ll j) { return i % j ? gcd(j, i % j) : j; }

int main() {
	
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll cd = c * d / gcd(c, d);
	ll div_c, div_d, div_cd;
	div_c = b / c - (a - 1) / c;
	div_d = b / d - (a - 1) / d;
	div_cd = b / cd - (a - 1) / cd;

	cout << (b - a + 1) - (div_c + div_d - div_cd) << endl;

}