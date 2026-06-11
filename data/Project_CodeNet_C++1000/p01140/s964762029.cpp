#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int qx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int qy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(void) {
	while(true) {
		ll n, m;
		cin>>n>>m;
		if(n==0 && m==0) return 0;
		vector<ll> h(n);
		vector<ll> w(m);
		REP(i, n) cin>>h[i];
		REP(i, m) cin>>w[i];
		vector<ll> s;
		ll ans = 0;
		REP(i, n) {
			ll shaku = 0;
			REP(j, n) {
				if(j <= i) shaku += h[j];
				else {
					s.pb(shaku);
					shaku -= h[j - (i + 1)];
					shaku += h[j];
				}
			}
			s.pb(shaku);
		}
		sort(ALL(s));
		REP(i, m) {
			ll shaku = 0;
			REP(j, m) {
				if(j <= i) shaku += w[j];
				else {
					ans += upper_bound(ALL(s), shaku) - lower_bound(ALL(s), shaku);
					shaku -= w[j - (i + 1)];
					shaku += w[j];
				}
			}
			ans += upper_bound(ALL(s), shaku) - lower_bound(ALL(s), shaku);
		}
		cout<<ans<<endl;
	}
}