#include <bits/stdc++.h>
using namespace std;
#define int ll
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
typedef long long ll;

signed main(){
	FASTIO
	int h, w, m;
	cin >> h >> w >> m;
	map<int, set<int> > mp;
	int r[h] = {0}, c[w] = {0};
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		mp[x].insert(y);
		r[x-1]++;
		c[y-1]++;
	}
	int mx = *max_element(r, r + h);
	vector<int> rw, cl;
	for(int i = 0; i < h; i++){
		if(r[i] == mx)
			rw.push_back(i+1);
	}
	int ans = mx;
	mx = *max_element(c, c + w);
	ans += mx;
	ans--;
	for(int i = 0; i < w; i++){
		if(c[i] == mx)
			cl.push_back(i+1);
	}
	bool f = true;
	for(int i = 0; i < rw.size() && f; i++){
		for(int j = 0; j < cl.size(); j++){
			if(mp[rw[i]].find(cl[j]) == mp[rw[i]].end()){
				ans++;
				f = false;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}