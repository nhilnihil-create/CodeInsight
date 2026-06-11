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
	int n;
	cin >>n ;
	VI p(n), sq(n);
	rep(i, n) cin >>p[i];
	rep(i, n) sq[p[i]-1] = i;
	ll ans =0;
	set<int> st;
	st.insert(-MD); st.insert(MD); st.insert(-MD-1); st.insert(MD+1);
	rep(j, 2){st.insert(-MD-j); st.insert(MD+j);}
	repr(zi, n-1, 0){
		ll z = sq[zi] +1;
		st.insert(z);
		auto it = st.find(z);
		ll l2 = max(0, *next(it, -1));
		ll l1 = max(0, *next(it, -2));
		ll r1 = min(n+1, *next(it,  1));
		ll r2 = min(n+1, *next(it,  2));

		ans += ((z-l2) * (r2-r1) + (l2-l1)*(r1-z) ) * p[z-1];
	}
	cout << ans <<"\n";
	return 0;
	
}
