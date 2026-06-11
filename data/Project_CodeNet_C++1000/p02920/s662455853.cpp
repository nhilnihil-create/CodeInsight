#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	set<pair<int, int>> mine, togo;
	
	for(int i = 0; i < (1<<n); i++) {
		int x;
		cin >> x;
		togo.emplace(x, i);
	}
	
	pair<int, int> mx = *togo.rbegin();
	togo.erase(mx);
	int dumb = -1;
	mx.second = dumb;
	mine.insert(mx);
	int m = 0;
	bool ok = true;
	while(togo.size()) {
		vector<pair<int, int>> now;
		for(auto p : mine) {
			auto it = togo.upper_bound(p);
			if(it == togo.begin()) {
				ok = false;
				break;
			}
			it--;
			now.push_back(*it);
			togo.erase(*it);
		}
		
		if(!ok) break;
		for(auto p : now) {
			p.second = dumb--;
			mine.insert(p);
		}
		m++;
	}
	
	
	cout << (ok ? "Yes" : "No") << endl;
	
}
