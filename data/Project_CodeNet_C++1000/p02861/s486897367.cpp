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
	ll n;	cin >> n;
	ll x[n], y[n];
	REP(i, n){
		cin >> x[i] >> y[i];
	}
	int route[] = {0, 1, 2, 3, 4, 5, 6, 7};
	double ave = 0;
	ll cnt = 0;

	do{
		REP(i, n-1){
			ave += sqrt(pow(x[route[i]]-x[route[i+1]], 2) + pow(y[route[i]]-y[route[i+1]], 2));
		}
		cnt++;
	}while( next_permutation(route, route+n) );

	printf("%.10lf", ave / cnt);

	return 0;
}
