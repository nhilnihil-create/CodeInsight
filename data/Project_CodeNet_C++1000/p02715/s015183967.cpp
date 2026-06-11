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
	int n ,k;
	cin >>n >>k;
	ll ans = 0;
	VL dp(k+5);
	rep2(i, 1, k+1) dp[i] = bpow(k/i, n);
	repr(i, k, 1){
		for(int j=2*i; j<=k; j+=i) (dp[i] += MD - dp[j]) %=MD;
		(ans += dp[i] * i) %=MD;
	}
	
	cout <<ans <<"\n";
	return 0;
}
