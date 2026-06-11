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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 1e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20, bs = 29;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ll sm = 0, x;
	vector<string> sts;
	vector<ll> ints;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		string a;
		ll b;
		cin >> a >> b;
		sts.push_back(a), ints.push_back(b);
	}
	string sng;
	cin >> sng;
	bool bien = 0;
	for(int i = 0; i < n; i++) {
		if(bien) sm += ints[i];
		if(sts[i] == sng) bien = 1;
	}
	cout << sm << '\n';
}
