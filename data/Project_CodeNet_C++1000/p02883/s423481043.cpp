#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
const double PI = acos(-1);
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; ll k;
	cin >>n >>k;
	VI a(n), f(n);
	rep(i, n) cin >>a[i];
	rep(i, n) cin >>f[i];
	
	sort(all(a));
	sort(f.rbegin(), f.rend());
	VL sm(n);
	rep(i, n) sm[i] = (ll)a[i] * f[i];
	
	auto ckd=[&](ll s){
		ll rtn = 0;
		rep(i, n) rtn += max(0LL, (sm[i] - s + f[i]-1)/f[i]);
		return rtn <= k;
	};
	
	ll hi=1LL<<55, lw=-1;
	while(hi - lw >1){
		ll md = (hi+lw)/2;
		(ckd(md)? hi: lw) = md;
	}
	cout << hi <<"\n";
	return 0;
}
