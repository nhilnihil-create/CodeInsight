#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()

const int  INF = 1 << 29;
const ll INFL = 1LL << 60;
const ll mod = 998244353;


int main() {

	ll m;
	cin >> m;

	ll ans = -1;
	ll cnt = -1;

	REP(i, m) {
		ll d, c;
		cin >> d >> c;
		ans += c;
		cnt += d * c;
	}
	
	ans += cnt / 9;
	cout << ans << endl;


}