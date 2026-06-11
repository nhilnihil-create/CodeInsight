#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	int n,m;
	cin >> n >> m;
	int a = 0, w = 0;
	vector<pair<int,int>> cnt(n,pair<int,int>(make_pair(0,0)));
	for (int i=0; i<m; i++) {
		int p;
		string s;
		cin >> p >> s;
		--p;
		if (cnt[p].first != 1) {
			if (s == "AC") {
				cnt[p].first = 1;
			} else {
				cnt[p].second++;
			}
		}
	}
	for (auto& e:cnt) {
		if (e.first == 1) {
			a++;
			w += e.second;
		}
	}
	
	cout << a << ' ' << w;
	
	return 0;
}
