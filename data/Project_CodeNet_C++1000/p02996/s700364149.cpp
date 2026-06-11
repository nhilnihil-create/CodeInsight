#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;


int main() {

	ll N;

	cin >> N;

	ll k, v;
	vector<pair<ll, ll> > tasks;


	rep(i, N) {
		cin >> v >> k;
		tasks.emplace_back(k, v);
	}

	sort(tasks.begin(), tasks.end());

	bool key = true;
	ll sum = 0;

	rep(i, N) {
		sum += tasks[i].second;
		if (tasks[i].first < sum) {
			key = false;
			break;
		}
	}

	if (key) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
