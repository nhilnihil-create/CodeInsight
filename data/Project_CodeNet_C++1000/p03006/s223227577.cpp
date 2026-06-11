#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

	vector <ll> x(N);
	vector <ll> y(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> x[ii] >> y[ii];
	}

	map <pair<ll, ll>, ll> m;
	ll cnt = 0;
	for (int ii = 0; ii < N; ++ii){
		for (int jj = 0; jj < N; ++jj){
			if (ii == jj){
				continue;
			}
			ll dx = x[ii] - x[jj];
			ll dy = y[ii] - y[jj];
			m[make_pair(dx, dy)]++;
			cnt = max(cnt, m[make_pair(dx, dy)]);
		}
	}

	cout << N - cnt << "\n";

	return 0;
}
