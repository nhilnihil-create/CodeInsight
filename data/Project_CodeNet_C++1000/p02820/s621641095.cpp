#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, k; cin >> n >> k;
	int r, s, p; cin >> r >> s >> p;
	map<char, int> score;
	score['s'] = r;
	score['p'] = s;
	score['r'] = p;
	string t; cin >> t;
	ll ret = 0;
	for (int i=0; i<k; i++) {
		char prev = t[i];
		ret += score[prev];
		char now;
		for (int j=1; i+k*j<n; j++) {
			now = t[i + k*j];
			if (prev==now) {
				prev = 'x';
				continue;
			} else {
				ret += score[now];
				prev = now;
			}
		}
	}
	cout << ret << endl;
	return 0;
}