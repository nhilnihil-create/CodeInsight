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
	int n, ans =0;
	cin >>n;
	vector<VI> zc(10, VI(10));
	rep(i, n){
		string  s = to_string(i+1);
		if(s[sz(s)-1]=='0') continue;
		zc[s[0]-'0'][s[sz(s)-1]-'0']++;
	}
	rep(i, n){
		string  s = to_string(i+1);
		if(s[sz(s)-1]=='0') continue;
		ans += zc[s[sz(s)-1]-'0'][s[0]-'0'];
	}
	cout << ans <<"\n";
	return 0;
}
