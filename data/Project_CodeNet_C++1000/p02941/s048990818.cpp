#include "bits/stdc++.h"
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
mt19937 rnd(time(NULL));

const int maxN = 2e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20, bs = 29;

int n, arr[maxN], brr[maxN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	priority_queue<ii> pq;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n; i++) {
		cin >> brr[i];
		if(brr[i] < arr[i]) {
			cout << "-1\n"; return 0;
		}
		if(brr[i] > arr[i])
			pq.push(ii(brr[i], i));
	}

	ll ans = 0;
	while(pq.size()) {
		auto cr = pq.top().se;
		pq.pop();
		int prv = (cr + n - 1) % n, nex = (cr + 1) % n;
		if(arr[prv] == brr[prv] && arr[nex] == brr[nex]) {
			int dff = brr[cr] - arr[cr];
			if(dff % (brr[prv] + brr[nex])) {
				cout << "-1\n"; return 0;
			}
			ans += dff / (brr[prv] + brr[nex]);
			brr[cr] = arr[cr];
			continue;
		}
		if(brr[cr] < brr[prv] + brr[nex]) {
			cout << "-1\n"; return 0;
		}
		ans += brr[cr] / (brr[prv] + brr[nex]);
		brr[cr] %= (brr[prv] + brr[nex]);
		if(brr[cr] < arr[cr]) {
			cout << "-1\n"; return 0;
		}
		if(brr[cr] > arr[cr])
			pq.push(ii(brr[cr], cr));
	}

	cout << ans << '\n';
}
