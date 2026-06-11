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

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, t;
	cin >>n >>t;
	vector<pii> vp(n);
	rep(i, n) cin >>vp[i].first >>vp[i].second;
	sort(all(vp));
	VL dp(t+5);
	ll ans = 0;
	rep(i, n) repr(j, t-1, 0) {
		int nj = min(j + vp[i].first, t+2);
		dp[nj] = max(dp[nj], dp[j]+vp[i].second);
		ans = max(ans, dp[nj]);
	}

	cout << ans <<"\n";
	return 0;
}
