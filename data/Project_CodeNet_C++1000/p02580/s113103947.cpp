#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;
const double PI=acos(-1);

int main(){
	ll h, w, m; cin >> h >> w >> m;
	set<pair<ll,ll>> s;
	map<ll,ll> ycnt;
	map<ll,ll> xcnt;
	for(int i = 0; i < m; i++){
		ll y, x; cin >> y >> x;
		y--; x--;
		ycnt[y]++; xcnt[x]++;
		s.insert({y, x});
	}
	vector<ll> ymaxindex; vector<ll> xmaxindex;
	ll ymax = 0; ll xmax = 0;
	for(auto i : ycnt){
		ymax = max(ymax, i.second);
	}
	for(auto i : ycnt){
		if(i.second == ymax){
			ymaxindex.push_back(i.first);
		}
	}
	for(auto i : xcnt){
		xmax = max(xmax, i.second);
	}
	for(auto i : xcnt){
		if(i.second == xmax){
			xmaxindex.push_back(i.first);
		}
	}
	ll ans = ymax + xmax - 1;
	for(auto i : ymaxindex){
		for(auto j: xmaxindex){
			if(s.find({i,j}) == s.end()){
				cout << ans + 1 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
}
