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
	int n; cin >>n;
	VI a(n+1), b(n+1);
	rep2(i, 1, n+1) cin >>a[i];
	
	repr(i, n, 1){
		ll sm = a[i];
		for(ll j=i+i; j<=n; j+=i) sm +=b[j];
		b[i] = sm%2;
	}
	VI ans;
	rep(i, n+1) if(b[i]==1) ans.push_back(i);
	cout << sz(ans)<<"\n";
	if(sz(ans)){
		for(auto x:ans) cout << x <<" "; cout <<"\n";
	}
	return 0;
}
