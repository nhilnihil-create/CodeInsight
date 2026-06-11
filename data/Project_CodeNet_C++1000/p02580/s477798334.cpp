#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int H,W,M;
	cin >> H >> W >> M;
	vector<pair<int,int>> a(M);
	map<int,int> h, w;
	REP(i,M){
		cin >> a[i].first >> a[i].second;
		h[a[i].first]++;
		w[a[i].second]++;
	}
	
	int hmax=0, wmax=0, hcount=0, wcount=0;
	map<int,int> hindex,windex;
	for(auto x: h){
		chmax(hmax, x.second);
	}
	for(auto x: w){
		chmax(wmax, x.second);
	}
	for(auto x: h){
		if(x.second==hmax) hcount++;
	}
	for(auto x: w){
		if(x.second==wmax) wcount++;
	}
	for(auto x: h){
		if(x.second==hmax) hindex[x.first]=wcount;
	}
	for(auto x: w){
		if(x.second==wmax) windex[x.first]=hcount;
	}

	
	for(auto x: a){
		if(hindex.find(x.first)!=hindex.end() && windex.find(x.second)!=windex.end()){
			hindex[x.first]--;
			windex[x.second]--;
		}else{
			continue;
		}
		if(hindex[x.first]==0) hindex.erase(x.first);
		if(windex[x.second]==0) windex.erase(x.second);
	}
	
	if(hindex.empty() || windex.empty()){
		cout << hmax+wmax-1 << endl;
	}else{
		cout << hmax+wmax << endl;
	}
	
	
	return 0;
}