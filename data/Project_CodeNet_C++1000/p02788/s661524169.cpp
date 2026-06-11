#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<ll,ll> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; ll d, a;
	cin >>n >>d >>a;
	vector<pii> ha(n);
	rep(i, n) cin >>ha[i].first >>ha[i].second;
	sort(all(ha));
	priority_queue<pii, vector<pii>, greater<pii> > q;
	ll ans = 0, crdm= 0;
	rep(i, n){
		for(;!q.empty() && q.top().first < ha[i].first;){
			crdm -= q.top().second; q.pop();
		}
		if(ha[i].second <= crdm) continue;
		ll asu = (ha[i].second - crdm + a -1) / a;
		ans += asu; crdm += a * asu;
		q.emplace(ha[i].first + 2*d, a*asu);
	}
	cout << ans <<"\n";
	return 0;
}
