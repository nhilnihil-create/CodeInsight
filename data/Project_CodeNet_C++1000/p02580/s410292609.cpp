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
		ll r,c;cin >> r >> c;
		--r;--c;
		row[r]++;
		col[c]++;
		s.insert({r,c});
	}
	ll mrow = 0;
	ll mcol = 0;
	rep(i,H) mrow = max(mrow,row.at(i));
	rep(i,W) mcol = max(mcol,col.at(i));

	vector<ll> is,js;
	rep(i,H) if( mrow == row.at(i) ) is.push_back(i);
	rep(i,W) if( mcol == col.at(i) ) js.push_back(i);

	ll ans = mrow + mcol;
	for(ll i : is ){
		for(ll j : js ){
			// i,jが重ならない(=ansがそのまま)のパターンを探す
			if( s.find({i,j}) != s.end() ) continue;
			cout << ans <<  endl;
			return 0;
		}
	}
	cout << --ans << endl;
}