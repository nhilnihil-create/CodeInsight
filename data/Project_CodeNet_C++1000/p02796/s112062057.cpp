#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll INF = 10010010010;

int main() {
	ll N;
	cin >> N;

	vector <pair<ll,ll>> r(N);
	for (int ii = 0; ii < N; ++ii){
		ll X, L;
		cin >> X >> L;
		int val1 = 
		r[ii].first = X + L;
		r[ii].second = X - L;
	}

	sort(r.begin(), r.end());

	ll ans = 0;
	ll tmp = -INF;
	for (int ii = 0; ii < N; ++ii){
		if (tmp <= r[ii].second) {
			ans++;
			tmp = r[ii].first;
		}
	}

	cout << ans << "\n";

	return 0;
}
