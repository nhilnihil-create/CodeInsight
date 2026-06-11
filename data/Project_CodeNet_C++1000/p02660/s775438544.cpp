#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii; typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <class F,class ...S> void dbg(const F& f, const S&...s){cerr <<f <<": "; dbg(s...);}

map<ll, int> fctm( ll x ){
	map<ll, int> fmp;
	for( ;x>=4 && x%2==0; x/=2)  fmp[2]++;
	for(ll d=3, q=x/d; q>=d ; q=x/d){if(x%d==0) fmp[d]++, x=q; else d +=2;}
	if(x!=1) fmp[x]++;
	return fmp;
}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	ll n;
	cin >>n;
	
	ll ans =0;
	for(auto& x: fctm(n)){
		int p = x.second, su =0;
		for(int i=1; p >= i; i++){
			su ++; p -=i;
		}
		ans += su;
	}
	
	cout << ans <<"\n";
	return 0;
}
