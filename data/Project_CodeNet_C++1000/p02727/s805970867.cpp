#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }



int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int x, y, a,b,c;
	cin >>x >> y >>a >>b >>c;
	
	VL p(a), q(b), r(c);
	rep(i, a) cin >>p[i];
	rep(i, b) cin >>q[i];
	rep(i, c) cin >>r[i];
	sort(p.rbegin(), p.rend());
	sort(q.rbegin(), q.rend());
	sort(r.rbegin(), r.rend());
	VL cr; cr.reserve(x+y);
	rep(i, x) cr.push_back(p[i]);
	rep(i, y) cr.push_back(q[i]);
	sort(all(cr));

	rep(i, min(x+y, c)){
		if(cr[i] < r[i]) cr[i] = r[i];
		else break;
	}
	ll ans = accumulate(all(cr), 0LL);
	cout << ans <<"\n";
	return 0;
}
