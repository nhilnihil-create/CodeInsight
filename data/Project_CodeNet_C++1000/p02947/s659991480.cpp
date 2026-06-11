#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll n, cnt = 0;
	string s;
	map<string, ll>mp;
	cin >> n;
	vector<ll>ana(n),memo(n+1,0);
	rep(i, n) {
		cin >> s;
		sort(all(s));
		memo[i + 1] = memo[i] + ll(i);
		mp[s]++;
	}
	for (auto m : mp)cnt += memo[m.second];
	cout << cnt << endl;
	return 0;
}

