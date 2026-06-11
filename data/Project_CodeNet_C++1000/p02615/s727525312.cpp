#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pair<int, int>>
#define mems(x, y) memset(x, y, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define forn(i, s, e) for(int i = s; i < (e); ++i)
#define FASTIO                                                                                     \
	ios_base::sync_with_stdio(false);                                                              \
	cin.tie(NULL);
#define FILEIO                                                                                     \
	freopen("./input.txt", "r", stdin);                                                            \
	freopen("./output.txt", "w", stdout);
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d)                                                                                  \
	for(auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); blockTime.second;  \
		debug("%s : %lld ms\n ",                                                                   \
			  d,                                                                                   \
			  chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() -   \
														  blockTime.first)                         \
				  .count()),                                                                       \
			 blockTime.second = false)
const int M = 1e9 + 7;

template <class T>
T ABS(const T& x) {
	return x > 0 ? x : -x;
}
ll gcd(ll n1, ll n2) { return n2 == 0 ? ABS(n1) : gcd(n2, n1 % n2); }
ll lcm(ll n1, ll n2) { return n1 == 0 && n2 == 0 ? 0 : ABS(n1 * n2) / gcd(n1, n2); }
ll ceil2(ll a, ll b) { return (a + b - 1) / b; }

int main() {
	FASTIO
#ifdef LOCAL
	FILEIO
#endif
	int n;
	cin >> n;
	vl arr(n);
	forn(i, 0, n) cin >> arr[i];
	sort(arr.rbegin(), arr.rend());
	priority_queue<pii> pq;
	pq.push({arr[1], arr[0]});
	ll ans = arr[0];
	for(int i = 2; i < n; ++i) {
		pii curr = pq.top();
		if(i != 2) pq.pop();
		pq.push({arr[i], curr.first});
		pq.push({arr[i], curr.second});
		// cout << curr.first << endl;
		ans += curr.first;
		// cout << ans << endl;
	}
	cout << ans << endl;

	return 0;
}