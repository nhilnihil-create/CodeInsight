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
	string s;
	cin >>s;
	
	ll ans =0;
	array<ll, 2019> dp, np;
	fill(all(dp), 0);
	rep(i, sz(s)){
		int d = s[i]-'0';
		fill(all(np), 0);
		rep(j, 2019){
			np[(j*10 + d)%2019] += dp[j];
		}
		np[d]++;
		swap(np, dp);
		ans += dp[0];
	}
	cout << ans <<"\n";
	return 0;
}
