#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PP pop_back
#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

	int n, k;
	cin >> n >> k;
	n++;
	ll out = 0;
	for (int i = k; i <= n; i++) {
		ll minposs = (ll)i * (i - 1) / 2LL;
		ll maxposs = (ll)i * ((n - 1) + n - i) / 2LL;
//		cout << minposs << ' ' << maxposs;
//		cout << endl;
		out = ((maxposs - minposs) % mod + (out % mod) + 1) % mod;
	}
	cout << out << endl;
	return 0;
}
