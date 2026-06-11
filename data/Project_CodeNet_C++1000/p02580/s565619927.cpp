#include<bits/stdc++.h>
using namespace std;

main(){
	int h,w,m; cin>>h>>w>>m;
	
	vector<pair<int,int>> v;
	vector<int> hcnt(h+1),wcnt(w+1),markh(h+1),markw(w+1);
	for(int i=0; i<m; i++){
		int c,d; cin>>c>>d;
		v.emplace_back(c,d);
		hcnt[c]++;
		wcnt[d]++;
	}
	int hmax=0, wmax=0;
	for(int i=1; i<=h; i++) hmax = max(hmax,hcnt[i]);
	for(int i=1; i<=w; i++) wmax = max(wmax,wcnt[i]);
	
	int cnth = 0;
	for(int i=1; i<=h; i++){
		if(hcnt[i]==hmax){
			markh[i] = 1;
			cnth++;
		}
	}
	int cntw = 0;
	for(int i=1; i<=w; i++){
		if(wcnt[i]==wmax){
			markw[i] = 1;
			cntw++;
		}
	}
	int cnt = cnth*cntw;
	for(auto x : v){
		if(markh[x.first] && markw[x.second]) cnt--;
	}
	if(cnt) cout<<hmax + wmax;
	else cout<<hmax + wmax - 1;
}