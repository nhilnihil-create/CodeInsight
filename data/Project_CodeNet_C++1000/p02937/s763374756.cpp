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
	string s, t;
	cin >>s >>t;
	
	vector<VI> sd(28);
	rep(i, sz(s)) sd[s[i]-'a'].push_back(i);
	for(auto z: t) if(sz(sd[z-'a']) <1){puts("-1"); return 0;}
	
	ll cr =-1, sh=0;
	for(auto x: t){
		int p = x -'a';
		auto it = lower_bound(all(sd[p]), cr+1);
		if(it == sd[p].end()){
			sh++; it = lower_bound(all(sd[p]), 0);
		}
		cr =*it;
	}
	cout << sh * sz(s) + cr +1<<"\n";
	return 0;
	
}
