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

ll dp[10001];

int main(){
	ll h, n;	cin >> h >> n;
	pair<ll, ll> magic[n];
	REP(i, n){
		cin >> magic[i].first >> magic[i].second;
	}

	REP(i, h+1)	dp[i] = -1;
	dp[0] = 0;
	REP(i, 1, h+1){
		REP(j, n){
			if( i - magic[j].first >= 0 ){
				if( dp[i] == -1 )	dp[i] = dp[i - magic[j].first] + magic[j].second;
				else				dp[i] = min(dp[i], dp[i - magic[j].first] + magic[j].second);
			}else{
				if( dp[i] == -1 )	dp[i] = dp[0] + magic[j].second;
				else				dp[i] = min(dp[i], dp[0] + magic[j].second);
			}
		}
	}

	cout << dp[h] << endl;

	return 0;
}
