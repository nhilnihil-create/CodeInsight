
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e18;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

ll mpow(ll x, ll n, ll m) {
	ll ans = 1; x %= m;
	while (n != 0) {
		if (n & 1) ans = ans * x % m;
		x = x * x % m;
		n = n >> 1;
	}
	return ans;
}

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> as(n+1);
	rep(i, n) cin >> as[i+1];

	vector<int> history;
	int current = 1;
	history.push_back(current);
	vector<int> visit(n+1, -1);
	visit[1] = 0;
	for (ll i = 1; i <= k; i++) {
		auto next = as[current];
		if (visit[next] >= 0) {
			ll rest = k - i;
			ll loop = history.size() - visit[next];
			rest %= loop;
			cout << history[visit[next] + rest] << endl;
			//end
			return 0;
		}
		history.push_back(next);
		visit[next] = i;		
		current = next;
	}
	cout << history.back() << endl;
	return 0;
}
