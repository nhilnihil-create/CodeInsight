#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector <vector<pair<int,int>>> a(n);
	for (int i = 0; i < n; ++i){
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j){
			int x, y;
			cin >> x >> y;
			a[i].emplace_back(x,y);	
		}
	}
	int cnt = -1;
	for (int i = 0; i < (1 << n); ++i){
		bool possible = true;
		int ans = __builtin_popcount(i);
		vector <bool> v(n);
		for (int mask = 0; mask < n; ++mask){
			if ((i & (1 << mask) )!= 0) v[mask] = true;
			else v[mask] = false;	
		}
		for (int mask = 0; mask < n; ++mask){
			if ((i & (1 << mask)) != 0){
				for (auto pp : a[mask]){
					if (v[--pp.first] != pp.second){
						possible = false;
						break;
					}
				}
			}
		}
		if (possible) cnt = max(cnt, ans);
	}
		cout << cnt << "\n";
	return 0;
}
