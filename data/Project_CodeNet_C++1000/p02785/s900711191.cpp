#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define _overload(_1, _2, _3, name, ...) name
#define _rep(i, n) for(ll i = 0; i < (ll)n; i++)
#define _repi(i, s, n) for(ll i = (ll)(s); i < (ll)n; i++)
#define REP(...) _overload(__VA_ARGS__, _repi, _rep,)(__VA_ARGS__)
#define all(v) (v).begin(),(v).end()
#define UNIQUE(v) (v).erase( unique( all(v) ), (v).end() );
#define MOD 1000000007

int main(){
	ll n, k;	cin >> n >> k;
	ll h[n];
	ll sum = 0;
	REP(i, n){
		cin >> h[i];
	}

	sort( h, h + n, greater<ll>() );

	REP(i, k, n){
		sum += h[i];
	}

	cout << sum << endl;

	return 0;
}
