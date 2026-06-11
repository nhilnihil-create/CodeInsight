#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	string s;
	cin >> n >> m >> s;
	set<int> st;
	rep(i,n+1){
		if(s[i] == '0') st.insert(i);
	}
	int cur = n;
	vector<int> ans;
	while(cur > 0){
		auto nex = st.lower_bound(cur-m);
		if(*nex >= cur){
			cout << "-1" << endl;
			return 0;
		}
		ans.push_back(cur - *nex);
		cur = *nex;
	}
	for(int i = ans.size()-1; i >= 0; --i){
		cout << ans[i];
		if(i != 0) cout << " ";
	}
	cout << endl;
	return 0;
}