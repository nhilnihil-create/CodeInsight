#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int N = 1000007, inf = 0x3f3f3f3f, M = 1e9 + 7;

ll fast_pow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) ans = ans * a % M;
		b >>= 1;
		a = a * a % M;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	// todos - (todos diferentes de 0) U (todos diferentes de 9)
	// todos - (todos diferentes de 0 + todos difern)

	ll n; cin >> n;
	ll todos = fast_pow(10ll, n);
	ll x = 2ll * fast_pow(9ll, n)%M ;
	x -= fast_pow(8ll, n);
	x += M;
	x %= M;
	cout << (todos - x + M)%M << endl;
}