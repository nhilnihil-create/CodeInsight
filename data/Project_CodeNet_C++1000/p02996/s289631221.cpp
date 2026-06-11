#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	map<ll, ll> W;
	for (int i=0; i<n; i++) {
		ll a, b; cin >> a >> b;
		if (W.count(b)) W[b] += a;
		else W[b] = a;
	}
	string ret = "Yes";
	ll cnt = 0; 
	for (auto p : W) {
		ll k = p.first;
		ll v = p.second;
		cnt += v;
		if (cnt > k) {
			ret = "No";
			break;
		}
	}
	cout << ret << endl;
	return 0;
}