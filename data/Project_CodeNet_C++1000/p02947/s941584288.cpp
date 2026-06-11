#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	map<string, ll> M;
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		M[s]++;
	}
	ll ret = 0;
	for (auto p : M) {
		ret += p.second * (p.second - 1) / 2;
	}
	cout << ret << endl;
	return 0;
}