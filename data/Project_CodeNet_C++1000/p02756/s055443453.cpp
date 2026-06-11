#include <bits/stdc++.h>
#include <unordered_set>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int reversed = 0;
	string s; cin >> s;

	deque<char> dq;
	for (char ch : s) dq.push_back(ch);

	int Q; cin >> Q;
	while (Q--) {
		int q; cin >> q;
		if (q == 1) reversed ^= 1;
		else {
			int f; char c;
			cin >> f >> c;
			if (f == 1) {
				if (reversed) dq.push_back(c);
				else dq.push_front(c);
			}
			else {
				if (reversed) dq.push_front(c);
				else dq.push_back(c);
			}
		}
	}

	if (!reversed) {
		for (int i = 0; i < dq.size(); i++) cout << dq[i];
	}
	else {
		for (int i = dq.size() - 1; i >= 0; i--) cout << dq[i];
	}
	return 0;
}