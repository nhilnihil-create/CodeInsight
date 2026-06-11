#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	ll n = s.size();
	vector<set<int>> st(26);
	rep(i,n){
		st[(s[i]-'a')].insert(i+1);
	}
	rep(i,26) st[i].insert(INF);
	int m = t.size();
	ll ans = 0, cur = 0;
	rep(i,m){
		int c = t[i] - 'a';
		auto itr = st[c].lower_bound(cur+1);
		if(*itr == INF){
			ans += n - cur;
			cur = 0;
			itr = st[c].lower_bound(cur);
		}
		if(*itr == INF){
			cout << -1 << endl;
			return 0;
		}
		ans += *itr - cur;
		cur = *itr;
	}
	cout << ans << endl;
	return 0;
}