#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii; typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <class F,class ...S> void dbg(const F& f, const S&...s){cerr <<f <<": "; dbg(s...);}

ll bpow(ll x,ll n,ll m=MD,ll r=1LL){for(;n>0;n>>=1,x=x*x%m) if(n&1) r=r*x%m; return r;}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	VI a(n+1), ans(n+1);
	rep(i, n-1) cin >>a[i+2];
	
	rep(i, n+1) ans[a[i]]++;
	
	rep2(i,1,n+1) cout <<ans[i] <<"\n";
	return 0;
}
