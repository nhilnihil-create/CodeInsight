#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int h, w, m;
	cin >> h >> w >> m;
	auto cntH = vector<int>(h);
	auto cntW = vector<int>(w);
	auto exist = set<pair<int, int>>();
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> y >> x;
		exist.insert(make_pair(x - 1, y - 1));
		++cntH[y - 1];
		++cntW[x - 1];
	}
	auto sortedH = vector<pair<int, int>>(h);
	auto sortedW = vector<pair<int, int>>(w);
	for(int i = 0; i < h; ++i){
		sortedH[i] = make_pair(cntH[i], i);
	}
	for(int i = 0; i < w; ++i){
		sortedW[i] = make_pair(cntW[i], i);
	}
	sort(sortedH.begin(), sortedH.end(), greater<pair<int, int>>());
	sort(sortedW.begin(), sortedW.end(), greater<pair<int, int>>());
	int maxHCnt = sortedH[0].first;
	int maxWCnt = sortedW[0].first;
	int ans = maxHCnt + maxWCnt;
	if(exist.find(make_pair(sortedW[0].second, sortedH[0].second)) != exist.end()){
		--ans;
		bool done = false;
		for(int i = 0; i < h; ++i){
			if(sortedH[i].first < maxHCnt) break;
			for(int j = 0; j < w; ++j){
				if(sortedW[j].first < maxWCnt) break;
				int x = sortedW[j].second;
				int y = sortedH[i].second;
				int s = sortedH[i].first + sortedW[j].first - (exist.find(make_pair(x, y)) == exist.end() ? 0 : 1);
				if(s > ans){
					ans = s;
					done = true;
				}else if(s < ans){
					done = true;
				}
				if(done) break;
			}
			if(done) break;
		}
	}
	cout << ans << endl;

	return 0;
}