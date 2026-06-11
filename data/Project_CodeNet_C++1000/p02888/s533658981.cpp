#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vl = vector<ll>;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(a) (a).begin(), (a).end()
ll n;
vl l;
int main() {
	cin >> n;
	l.resize(n);
	REP(i, n){
		cin >> l[i];
	}
	sort(ALL(l));
	ll ans = 0;
	REP(i, n){
		FOR(j, i+1, n){
			auto ite = upper_bound(l.begin() + j + 1, l.end(), abs(l[i]-l[j]));
			auto ite2 = lower_bound(l.begin() + j + 1, l.end(), l[i]+l[j]);
			ans += ite2 - ite;
		}
	}
	cout << ans << endl;
	return 0;
}
