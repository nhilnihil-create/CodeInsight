#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii; typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <class F,class ...S> void dbg(const F& f, const S&...s){cerr <<f <<": "; dbg(s...);}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >>n >>m >>q;
	VI a(q), b(q), c(q), d(q);
	rep(i, q){ cin >>a[i] >>b[i] >>c[i] >>d[i]; a[i]--; b[i]--;}
	int ans = 0;
	rep(msk, 1<<(n+m-1)){
		if(__builtin_popcount(msk) !=n ) continue;
		VI v; int ct =0;
		rep(i, n+m-1){ if(msk>>i &1) v.push_back(ct); else ct++;}
		int sm = 0;
		rep(i, q) if(v[b[i]] - v[a[i]] == c[i]) sm += d[i];
		ans = max(ans, sm);
	}
	cout <<ans <<"\n";
	return 0;
}
