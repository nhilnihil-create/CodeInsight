#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int H, W, m;
	cin >> H >> W >> m;
	map<int, ll> y, x;
	int my = -1, mx = -1;
	set<P> st;
	rep(i,m){
		int h, w;
		cin >> h >> w;
		st.insert(P(h, w));
		++y[h];
		++x[w];
		if(y[my] < y[h]) my = h;
		if(x[mx] < x[w]) mx = w;
	}
	vector<int> hh, ww;
	for(auto p : y){
		if(p.second == y[my]) hh.push_back(p.first);
	}
	for(auto q : x){
		if(q.second == x[mx]) ww.push_back(q.first);
	}
	ll ans = y[my] + x[mx];
	for(auto p : hh){
		for(auto q : ww){
			if(st.find(P(p, q)) == st.end()){
				cout << ans << endl;
				return 0;
			}
		}
	}
	--ans;
	cout << ans << endl;
	return 0;
}
