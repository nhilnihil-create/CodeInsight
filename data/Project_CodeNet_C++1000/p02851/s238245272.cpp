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
	int n; ll k;
	cin >>n >>k;
	VL a(n), sm(n+1);
	rep(i, n) {cin >>a[i]; a[i]--;}
	rep(i, n) sm[i+1] = (sm[i] + a[i] )%k;
	
	map<ll, int> mp;
	ll ans =0;
	rep(i, n+1){
		if(i-k>=0) mp[sm[i-k]]--;
		//dbg(i, sm[i], mp[sm[i]]);
		ans += mp[sm[i]];
		mp[sm[i]]++;
	}
	cout << ans <<"\n";
	return 0;
}
