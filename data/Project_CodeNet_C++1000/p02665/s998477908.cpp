#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	VL a(n+1);
	
	rep(i, n+1) cin >>a[i];
	if(n==0){ puts(a[0]==1? "1":"-1"); return 0;}
	if(a[0]>0 && n>0){ puts("-1");return 0;}
	if(a.back()==0){ puts("-1");return 0;}
	const ll INF = 1LL<<61;
	VL mz(n+1), pz(n+1);
	mz[0]=1;
	rep(i, n){
		mz[i+1]=min(INF, (mz[i] - a[i]) * 2LL);
		if(mz[i]<a[i]){ { puts("-1");return 0;}}
	}
	ll cr=0;
	repr(i, n, 0){
		cr += a[i];
		pz[i] = cr;
	}
	//for(auto x :mz) cerr<<x<<" "; dbg();
	//for(auto x :pz) cerr<<x<<" "; dbg();
	ll ans = 0;
	rep(i, n+1){
		if(mz[i] < a[i]){puts("-1");return 0;}
		ans += min(pz[i], mz[i]);
	}
	cout << ans <<"\n";
	return 0;
}
