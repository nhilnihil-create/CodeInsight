#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9+100;

const int S = 4e5;
int rcnt[S] = {0};
int ccnt[S] = {0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	set<pair<int,int>> m;
	int h, w, n;
	cin>>h>>w>>n;
	int mxr = 0, mxc = 0;
	for (int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		rcnt[y]++;
		ccnt[x]++;
		mxr = max(rcnt[y], mxr);
		mxc = max(ccnt[x], mxc);
		m.emplace(x, y);
	}
	vector<int> mxRows, mxCols;
	for (int i = 0; i < S; i++){
		if (rcnt[i] == mxr){
			mxRows.push_back(i);
		}
		if (ccnt[i] == mxc){
			mxCols.push_back(i);
		}
	}
	for (auto &it: mxRows){
		for (auto &itt: mxCols){
			if (m.count({itt, it}) == 0){
				cout<<mxr+mxc<<'\n';
				return 0;
			}
		}
	}
	cout<<mxr+mxc-1<<'\n';
		
	return 0;
}

// bool f = 1;
			// for (auto &itt: it.second){
			// 	if (p.count(itt) == 0){
			// 		cout<<rmax+cmax<<'\n';
			// 		return 0;
			// 	}
			// }
