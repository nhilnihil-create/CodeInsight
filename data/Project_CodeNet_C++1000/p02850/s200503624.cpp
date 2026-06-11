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
	cin >>n;
	vector<vector<pii>> r(n);
	VI cnt(n), ps(n);
	rep(i, n-1){
		int a, b; cin >>a >>b;
		r[a-1].emplace_back(b-1, i);
		r[b-1].emplace_back(a-1, i);
		cnt[a-1]++; cnt[b-1]++;
	}
	int bmx = *max_element(all(cnt));
	
	auto f =[&](auto f, int s, int c, int p=-1)->void{
		int nc = c;
		for(auto x: r[s]) if(p != x.first){
			nc = (nc + 1) %bmx;
			ps[x.second] = nc;
			f(f, x.first, nc, s);
		}
	};
	f(f, 0, -1,-1);
	cout <<bmx <<"\n";
	rep(i, n-1) cout<<ps[i]+1<<"\n";
	return 0;
}
