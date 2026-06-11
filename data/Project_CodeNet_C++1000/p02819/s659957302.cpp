#include <bits/stdc++.h>
#include <unordered_map>

const double PI = acos(-1);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000
#define LLINF 1e18

// 素数判定
bool is_prime(ll n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

void solve_abc_c() {
	ll n, m;
	ll k;
	ll h, w;
	//ll x;
	//ll a;
	string s;
	string s_ans;
	ll l_ans = 0;
	double d_ans = 0;

	cin >> n;

	rep2(i, n, n * 2) {
		if (is_prime(i)) {
			cout << i << "\n";
			return;
		}
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_c();

	return 0;
}
