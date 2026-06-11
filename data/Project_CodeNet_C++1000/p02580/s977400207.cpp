#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

ll n, m, k;

int main() {
	cin >> n >> m >> k;

	vector<ll> prefx(n + 2), x(k + 1);
	vector<ll> prefy(m + 2), y(k + 1);

	for (ll i = 1; i <= k; i ++) {
		cin >> x[i] >> y[i];

		prefx[x[i]]++; prefx[x[i] + 1]--;
		prefy[y[i]]++; prefy[y[i] + 1]--;
	}

	for (ll i = 1; i <= n; i ++) {
		prefx[i] += prefx[i - 1];
	}

	for (ll i = 1; i <= m; i++) {
		prefy[i] += prefy[i - 1];
	}

	ll maxx = -1;
	for (ll i = 1; i <= n; i ++) {
		maxx = max(maxx, prefx[i]);
	}

	ll maxy = -1;
	for (ll i = 1; i <= m; i ++) {
		maxy = max(maxy, prefy[i]);
	}

	ll cntx = 0;
	for (ll i = 1; i <= n; i++) {
		if (prefx[i] == maxx) {
			cntx++;
		}
	}

	ll cnty = 0;
	for (ll i = 1; i <= m; i ++) {
		if (prefy[i] == maxy) {
			cnty++;
		}
	}

	ll count = 0;
	for (ll i = 1; i <= k; i ++) {
		if (prefx[x[i]] + prefy[y[i]] == maxx + maxy) {
			count++;
		}
	}

	if (count == cntx * cnty) {
		cout << maxx + maxy - 1 << endl;
	}
	else {
		cout << maxx + maxy << endl;
	}

	return 0;
}