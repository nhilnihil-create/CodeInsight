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
	int  n, m;
	cin >>n >>m;
	VI h(n);
	rep(i, n) cin >>h[i];
	vector<VI> r(n);
	rep(i, m){
		int a, b;
		cin >>a >>b;
		r[a-1].push_back(b-1);
		r[b-1].push_back(a-1);
	}
	int ans =0;
	rep(i, n){
		bool ok=1;
		for(auto w: r[i]) if(h[w] >= h[i]) ok=0;
		ans += ok;
	}
	cout << ans <<"\n";
	return 0;
}
