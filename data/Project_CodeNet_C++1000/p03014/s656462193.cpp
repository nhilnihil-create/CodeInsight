#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int h, w;
	cin >>h >>w;
	vector<string> vs(h);
	rep(i, h) cin >>vs[i];
	vector<VI> p(h, VI(w));
	
	auto f=[&](VI& v){
		int n = sz(v);
		rep2(i, 1, n) if(v[i]==1) v[i] = v[i-1] +1;
		repr(i, n-2, 0) if(v[i]>0 && v[i]<v[i+1]) v[i]=v[i+1];
	};
	
	rep(i, h){
		VI cr(w);
		rep(j, w) if(vs[i][j]=='.') cr[j] = 1;
		f(cr);
		//for(auto x :cr) cerr<<x<<" "; dbg();
		rep(j, w) p[i][j] += cr[j];
	}
	rep(i, w){
		VI cr(h);
		rep(j, h) if(vs[j][i]=='.') cr[j] = 1;
		f(cr);
		rep(j, h) p[j][i] += cr[j];
	}
	int ans = 0;
	rep(i, h) rep(j, w) ans = max(ans, p[i][j]);
	cout << (ans? ans -1: 0) <<"\n";
	return 0;
}
