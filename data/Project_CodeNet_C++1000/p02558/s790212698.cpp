#include <bits/stdc++.h>
#include <atcoder/dsu>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;
using namespace atcoder;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	dsu dsu(n);
	rep(i, q){
		int t, u, v;
		cin >> t >> u >> v;

		if(t == 0){
			dsu.merge(u, v);
		}else{
			cout << dsu.same(u, v) << endl;
		}
	}
}
