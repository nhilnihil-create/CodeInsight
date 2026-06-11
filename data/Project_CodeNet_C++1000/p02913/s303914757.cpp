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

VI zalgorithm(const string &s) {
	VI prfx(s.size());
	for(int i =1, j =0; i < sz(s); i++) {
		if(i + prfx[i - j] < j + prfx[j]) {
			prfx[i] = prfx[i - j];
		} else {
			int k = max(0, j + prfx[j] - i);
			while(i + k < sz(s) && s[k] == s[i + k]) ++k;
			prfx[i] = k;
			j = i;
		}
	}
	prfx[0] = sz(s);
	return prfx;
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; string s;
	cin >>n >>s;
	int ans = 0;
	rep(i, n){
		string z = s.substr(i);
		auto v = zalgorithm(z);
		rep(j, sz(z)){
			int q=v[j];
			q = min(q, j);
			ans = max(ans, q);
		}
	}
	
	cout <<ans <<"\n";
	return 0;
	
}
