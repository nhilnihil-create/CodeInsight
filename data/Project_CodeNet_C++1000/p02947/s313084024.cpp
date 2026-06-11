#include "bits/stdc++.h"
using namespace std;

//47
typedef long long ll;

int main() {
	int n;
	cin >> n;
	//vector<string> v(n);
	map<string,int> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		sort(s.begin(),s.end());
		m[s]++;
	}
	//sort(v.begin(),v.end());
	//int ans = 0;
	//map<string,int> m;
	//for (int i = 0; i < n; ++i) {
		//m[v[i]]++;
	//}
	ll ans = 0;
	for (auto it = m.begin(); it != m.end(); ++it) {
		if (it->second > 1) {
			ans += 1LL * ((it->second *1LL * (it->second - 1)) / 2);
		}
	}
	cout << ans;
}
