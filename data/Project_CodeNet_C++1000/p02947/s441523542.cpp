#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int n;
	ll ans = 0;
	cin >> n;
	std::map<string, ll> map;
	rep(i, n){
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		map[s]++;
	}
	for (auto p : map){
		auto value = p.second;
		if (value > 1) ans += value*(value-1)/2;
	}
	cout << ans << endl;
	return 0;
}
