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
	int n;
	string s;
	cin >>n >>s;
	
	VI z(n);
	rep(i, n) z[i] = s[i]=='R'? 0: s[i]=='G'? 1: 2;
	vector<VI> sm(3, VI(n+1));
	rep(i, n) rep(j, 3){
		sm[j][i+1] = sm[j][i] + (j==z[i]);
	}
	ll ans = 0;
	
	rep(i, n) rep2(j, i+1, n) if(z[i] !=z[j]){
		int p = (z[i]+z[j]==3)? 0 : (z[i]+z[j]==2)? 1: 2;
		ans += sm[p][n] - sm[p][j+1];
		if(j-i + j < n && z[j-i+j] == p) ans--; 
	}
	cout <<ans <<"\n";
	return 0;
}
