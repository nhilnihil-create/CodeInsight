#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int N; cin >> N;
	vector<pair<ll, ll>> task(N);
	rep(i, N) {
		cin >> task[i].second >> task[i].first;
	}

	sort(task.begin(), task.end());

	bool ans = true;

	ll t = 0;
	for (auto x : task) {
		t += x.second;
		if (t > x.first) {
			ans = false;
			break;
		}
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}