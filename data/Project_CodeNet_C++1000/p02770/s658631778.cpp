#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353

int main(){
	ll k, q, n, x, y, m, cnt, ans, dvr, lef, divd, addit;
	cin >> k >> q;
	vector<ll> d(k);
	REP(i,k) cin >> d.at(i);

	REP(i,q){
		cin >> n >> x >> m;
		ans = 0;
		dvr = (n-1)/k;
		lef = ((n-1) % k);
		cnt = x % m;
		REP(i,k){
			addit = 0;
			if (i <= lef-1) addit = 1;
			divd = d.at(i) % m;
/*			cout << i << " " << addit << " " << dvr << endl;*/
			if (divd == 0){
				ans += (addit+dvr);
			}
			cnt += divd * (addit+dvr);
		}
		ans += cnt/m;
		cout << n-ans-1 << endl;
	}
}