#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >>n;
	VL a(n);
	rep(i, n) cin >>a[i];

	VL sm(62);
	rep2(i, 0, 62) rep(j, n) if(a[j]>>i &1) sm[i]++;

	ll ans = 0;
	rep(i, 62){
		(ans += (1LL<<i) %MD * sm[i] %MD * (n-sm[i])) %=MD;
	}
	
	cout <<ans <<"\n";
	return 0;
}
