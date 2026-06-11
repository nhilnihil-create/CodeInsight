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
	string s;	cin >> s;
	bool ans = true;

	if( n % 2 == 0 ){
		REP(i, n/2){
			if( s[i] != s[i + n/2] )	ans = false;
		}

		if( ans )	cout << "Yes" << endl;
		else		cout << "No" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}
