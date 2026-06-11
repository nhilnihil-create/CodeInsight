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

	int n, k, c;
	string str;
	cin >> n >> k >> c >> str;
	vector<int> inds;
	for(int i = 0; i < n; i++)
		if(str[i] == 'o') inds.push_back(i);
	vector<int> mxi(inds.size() + 1);

	for(int i = inds.size() - 1; i >= 0; i--) {
		int w = int(lower_bound(inds.begin(), inds.end(), inds[i] + c + 1) - inds.begin());
		mxi[i] = mxi[w] + 1;
	}

	if(mxi[0] > k) return 0;
	for(int i = 0; i < inds.size(); i++) LOG << inds[i] << ' ' << mxi[i] << '\n';

	int prv;
	for(int i = 0, j = 0; i < inds.size(); i = j) {
		for(; j < inds.size() && mxi[i] == mxi[j]; j++);
		//LOG << "prv " << prv << '\n';
		if(!i) {
			if(j - i == 1) cout << inds[i] + 1 << '\n';
			prv = inds[0];
		} else {
			if(j - i == 1 || prv + c + 1 > inds[j - 2]) cout << inds[j - 1] + 1 << '\n';
			prv = *lower_bound(inds.begin(), inds.end(), prv + c + 1);
		}
	}
}

