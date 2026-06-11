#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n, t;
	cin >> n >> t;
	vector<pair<int, int>> vp(n);
	rep(i, n){
		int a, b;
		cin >> a >> b;
		vp.at(i) = make_pair(a, b);
	}
	sort(vp.begin(), vp.end());
	vector<vector<int>> dp(n, vector<int>(t));
	rep(i, t) dp.at(0).at(i) = 0;
	rep2(i, 1, n){
		auto add = vp.at(i-1);
		rep(j, t){
			int a1, a2 = -1;
			a1 = dp.at(i-1).at(j);
			if(0 <= j - add.first) a2 = dp.at(i-1).at(j - add.first) + add.second;
			dp.at(i).at(j) = max(a1, a2);
		}
	}
	int ans = 0;
	rep(i, n){
		int last = vp.at(i).second;
		ans = max(ans, dp.at(i).at(t-1) + last);
	}
	cout << ans << endl;
	return 0;
}