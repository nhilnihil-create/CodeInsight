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
	vector<set<int>> v(26);
	rep(i,n){
		int id = s[i] - 'a';
		v[id].insert(i+1);
	}
	rep(i,26){
		v[i].insert(INF);
	}
	ll cur = 0, loop = 0;
	rep(i,t.size()){
		int id = t[i] - 'a';
		auto p = v[id].lower_bound(cur+1);
		if(*p == INF){
			++loop;
			cur = 0;
			p = v[id].lower_bound(0);
		}
		if(*p == INF){
			cout << -1 << endl;
			return 0;
		}
		cur = *p;
	}
	ll ans = loop * n + cur;
	cout << ans << endl;
	return 0;
}