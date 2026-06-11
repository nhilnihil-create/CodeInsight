#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<ll, ll> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	string s;
	cin >>s;
	s+="00";
	int n=sz(s);
	const ll INF = 1e18;
	VL dp = {0, INF};
	rep(i, n){
		VL nxt(2, INF);
		rep(j, 2) rep(d, 10){
			int nj = j + s[i] -'0';
			int pc = d - nj + (d<nj? 10: 0);
			nxt[d < nj] = min(nxt[d<nj], dp[j] +pc +d);
		}
		swap(dp, nxt);
	}
	cout << dp[0] <<"\n";
	return 0;
}
