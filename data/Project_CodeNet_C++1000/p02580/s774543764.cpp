#include <bits/stdc++.h>
using namespace std;
vector<int> in_column;
multiset<int> best;
void update(int pos, int delta){
	best.erase(best.find(in_column[pos]));
	in_column[pos] += delta;
	best.insert(in_column[pos]);
}
int main(){
	int h, w, m; cin >> h >> w >> m;
	vector<vector<int>> in_row(h);
	in_column = vector<int>(w);
	for(int i = 0; i < m; i++) best.insert(0);
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		x--, y--;
		in_row[x].push_back(y);
		update(y, 1);
	}
	int res = 0;
	for(int i = 0; i < h; i++){
		int cur = in_row[i].size(); 
		for(int x : in_row[i]) update(x, -1);
		if(best.size()) cur += *best.rbegin();
		res = max(res, cur);
		for(int x : in_row[i]) update(x, 1);
	}
	cout << res << '\n';
	return 0;
}

