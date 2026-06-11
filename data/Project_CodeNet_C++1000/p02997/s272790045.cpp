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
	ll n, k;
	cin >> n >> k;
	vector<vector<ll>> ansl;
	ll lmt = (n-1)*(n-2)/2;
	FOR(i,2,n) FOR(j,i+1,n) ansl.pb({i,j});
	if (k > lmt){
		cout << -1 << endl;
	}
	else{
		cout << lmt+n-k-1 << endl;
		FOR(i,2,n) cout << 1 << " " << i << endl;
		ll cnter = 0;
		while (cnter < lmt-k){
			cout << ansl.at(cnter).at(0) << " " << ansl.at(cnter).at(1) << endl;
			cnter++;
		}
	}
}