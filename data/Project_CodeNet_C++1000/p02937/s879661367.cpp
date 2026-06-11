#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

string S, T;
int sz_s, sz_t;
vector<vi> C;

void input_init(void) {
	cin >> S >> T;
	sz_s = S.length();
	sz_t = T.length();
	C.resize(26);
	for (int i = 0; i < sz_s; ++i) {
		int idx = (int)(S[i] - 'a');
		C[idx].push_back(i);
	}
}

bool enable(void) {
	bool ret = true;
	for (int i = 0; i < sz_t; ++i) {
		int idx = (int)(T[i] - 'a');
		if (C[idx].size() == 0) {
			ret = false;
			break;
		}
	}
	return ret;
}

ll solve(void) {
	int cnt = 0;
	int sp = 0;
	int st = 0;
	int pre = -1;
	while (st < sz_t) {
		int idx = (int)(T[st] - 'a');
		vector<int>::iterator itr;
		itr = upper_bound(C[idx].begin(), C[idx].end(), pre);
		if (itr == C[idx].end()) {
			++cnt;
			pre = -1;
		}
		else {
			pre = *itr;
			++st;
		}
	}
	ll ret = (ll)sz_s * cnt + pre + 1;
	return ret;
}

int main(void) {
	input_init();
	ll ans = (ll)-1;
	if (enable())
		ans = solve();
	cout << ans << '\n';
	return 0;
}
