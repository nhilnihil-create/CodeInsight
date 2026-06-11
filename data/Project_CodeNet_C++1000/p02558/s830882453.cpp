#include <bits/stdc++.h>
#include <atcoder/all>

typedef long long ll;
using namespace std;
using namespace atcoder;

#define _overload(_1, _2, _3, name, ...) name
#define _rep(i, n) for(ll i = 0; i < (ll)n; i++)
#define _repi(i, s, n) for(ll i = (ll)(s); i < (ll)n; i++)
#define REP(...) _overload(__VA_ARGS__, _repi, _rep,)(__VA_ARGS__)
#define all(v) (v).begin(),(v).end()
#define UNIQUE(v) (v).erase( unique( all(v) ), (v).end() );
#define MOD 1000000007

int main(){
	ll n, q;	cin >> n >> q;
	dsu g(n);
	ll t, u, v;
	REP(i, q){
		cin >> t >> u >> v;
		if( t == 0 ){
			g.merge(u, v);
		}else{
			if( g.same(u, v) )	cout << 1 << endl;
			else				cout << 0 << endl;
		}
	}

	return 0;
}
