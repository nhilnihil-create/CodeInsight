#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt = 0;
	map<string, int> mp;
	rep(i,n){
		string s;
		cin >> s;
		chmax(cnt, ++mp[s]);
	}
	vector<string> ans;
	for(auto p : mp){
		if(p.second == cnt) ans.push_back(p.first);
	}
	sort(ans.begin(), ans.end());
	rep(i,ans.size()) cout << ans[i] << endl;
	return 0;
}