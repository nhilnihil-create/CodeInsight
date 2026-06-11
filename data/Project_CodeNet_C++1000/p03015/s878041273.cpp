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
	string l;
	cin >> l;
	ll n = l.size();
	vector<ll> li(l.size());
	transform(l.begin(),l.end(),li.begin(),[](char ch){return ch - '0';});
	vector<ll> powe(110001);
	powe.at(0) = 1;
	FOR(i,1,110000) powe.at(i) = (powe.at(i-1)*2) % MOD;
	vector<ll> dp(110000);
	dp.at(0) = 1;
	FOR(i,1,109999) dp.at(i) = (dp.at(i-1)*3) % MOD;
	ll ans = 0;
	ll cnt = 0;
	REP(i,n){
		if (li.at(i) == 1){
			ans = (ans+dp.at(n-i-1)*powe.at(cnt)) % MOD;
			cnt++;
			//cout << "li.at(i)==1, " << dp.at(n-i-1) << " " << powe.at(cnt) << endl;
		}
		
		//cout << i << "桁目finish, cnt=" << cnt << " " << ans << endl;
	}
	ans = (ans+powe.at(cnt)) % MOD;
	cout << ans << endl;
}