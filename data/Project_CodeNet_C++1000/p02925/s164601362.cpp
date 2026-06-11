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
	vector<deque<int>> a(n, deque<int>(n-1));
	rep(i, n) rep(j, n-1){ cin >>a[i][j]; a[i][j]--;}
	int ans = 0;
	set<pii> q;
	
	auto mkmc=[&](int c){
		if(sz(a[c]) ==0) return;
		int tb = a[c].front();
		if(a[tb].front() != c) return;
		q.emplace(min(c, tb), max(c, tb));
	};
	
	rep(i, n) mkmc(i);

	while(sz(q)){
		ans++;
		set<pii> cq;
		swap(q, cq);
		for(auto x: cq){
			a[x.first].pop_front();
			a[x.second].pop_front();
		}
		for(auto x: cq){
			mkmc(x.first);
			mkmc(x.second);
		}
	}
	rep(i, n) if(sz(a[i])>0) ans =-1;
	cout <<ans <<"\n";
	return 0;
	
}
