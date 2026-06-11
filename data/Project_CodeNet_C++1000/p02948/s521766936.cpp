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
	int n, m;
	cin >>n >>m;
	vector<VI> dt(101000);
	rep(i, n){
		int a, b; cin >>a >>b;
		dt[a].push_back(b);
	}
	ll ans =0;
	priority_queue<int> pq;
	rep(i, m+1){
		for(auto x: dt[i]) pq.emplace(x);
		if(!pq.empty()){
			ans += pq.top(); pq.pop();
		}
	}
	cout <<ans <<"\n";
	return 0;
	
}
