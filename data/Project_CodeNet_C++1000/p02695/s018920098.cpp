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
	VL a(q), b(q), c(q), d(q);
	rep(i, q){ cin >>a[i] >>b[i] >>c[i] >>d[i]; a[i]--; b[i]--;}
	
	VI ks(n);
	auto rec=[&](auto rec, int z, int pi){
		ll ans = 0;
		if(z == n){
			ll sm = 0;
			rep(i, q){
				if(ks[b[i]] - ks[a[i]] == c[i]) sm += d[i];
			}
			return sm;
		}
		
		rep2(i, pi, m){
			ks[z] = i;
			ans = max(ans, rec(rec, z+1, i));
		}
		return ans;
	};
	cout << rec(rec, 0, 0) <<"\n";
	return 0;
}
