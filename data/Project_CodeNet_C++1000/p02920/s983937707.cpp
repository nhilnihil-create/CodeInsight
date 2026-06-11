#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
//typedef pair<ll, P> T;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define revrep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define f first
#define s second
#define pb push_back

const ll mod = 1000000007;
const ll INF = 100000000000010000;

ll kai[100010];
ll bit[700010];

//void pres(double A, ll x = 20) { printf("%.20f\n", x); }

/*ll sum(ll i)
{
	ll s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(ll i, ll x)
{
	while (i <= 700005)
	{
		bit[i] += x;
		i += i & -i;
	}
}*/

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

ll pow_mod(ll x, ll y) {
	if (y == 0) return 1;
	if (y % 2 == 1) {
		return x * pow_mod(x, y - 1) % mod;
	}
	else {
		ll half = pow_mod(x, y / 2);
		return half * half % mod;
	}
}

ll div_mod(ll x) {
	return pow_mod(x, mod - 2);
}

ll com(ll x, ll y) {
	return kai[x] * div_mod(kai[y] * kai[x - y] % mod) % mod;
}

ll N;
ll S[1 << 18];
bool judge;
priority_queue<ll> que[18];

void solve() {
	cin >> N;
	rep(i, 1 << N) cin >> S[i];
	sort(S, S + (1 << N));
	reverse(S, S + (1 << N));
	rep(i, N) que[i].push(S[0]);
	rep(i, 1 << N) {
		if (i == 0) continue;
		rep(j, N) {
			if (que[j].size() == 0) continue;
			if (que[j].top() > S[i]) {
				que[j].pop();
				for (int k = j + 1; k < N; k++) {
					que[k].push(S[i]);
				}
				break;
			}
		}
	}
	judge = true;
	rep(i, N) {
		if (que[i].size() > 0) judge = false;
	}
	if (judge) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	ll N;
	cin >> N;
}
////////////////////////////////////////////////////////////////////////////////////////////jagfhaoi;sd;joi;asdfjzasdi;lfjoi;ernjsdoivcnoizvdfnvdfnon/////////////////////////////////////////////////////////
////////////////////jgoiadhsjgoi;vsjvgfonhjasoivhoivhno