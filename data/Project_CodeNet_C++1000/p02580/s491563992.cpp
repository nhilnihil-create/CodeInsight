#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;


int main() {
	ll H,W,M;cin >> H >> W >> M;
	vector<ll> row(H),col(W);
	set<P> s;
	rep(i,M){
		ll h,w;cin >> h >> w;
		--h;--w;
		row.at(h)++;
		col.at(w)++;
		s.insert({h,w});
	}
	ll rowmax = 0;
	ll colmax = 0;
	rep(i,H) rowmax = max(rowmax,row.at(i));
	rep(i,W) colmax = max(colmax,col.at(i));

	vector<ll> rowmax_array,colmax_array;
	rep(i,H) if( row.at(i) == rowmax ) rowmax_array.push_back(i);
	rep(i,W) if( col.at(i) == colmax ) colmax_array.push_back(i);

	ll ans = rowmax + colmax;
	for( auto p : rowmax_array ){
		for( auto q : colmax_array ){
			if( s.count({p,q}) ) continue;
			cout << ans << endl;
			return 0;
		}
	}

	cout << --ans << endl;

}