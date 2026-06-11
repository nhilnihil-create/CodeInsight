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
	int n, k;
	cin >>n >>k;
	ll ans =0;
	auto sms=[](ll l, ll r){return (l+r)*(r-l+1)/2;};
	rep2(i, k, n+2){
		ll st = sms(0, i-1);
		ll ed = sms(n-i+1, n);;
		//dbg(i,st,ed);
		(ans += ed +1 - st) %=MD;
	}
	cout << ans <<"\n";
	return 0;
}
