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
	int n;
	cin >> n;
	set<string> ans;
	ans.insert("a");
	rep2(i, 1, n){
		set<string> ad_st;
		for(string t : ans){
			set<char> temp;
			rep(i, t.size()){
				temp.insert(t[i]);
			}
			rep(j, temp.size()+1){
				string add = t;
				char bc = 'a' + j;
				add.push_back(bc);
				ad_st.insert(add);
			}
		}
		ans = ad_st;
	}
	for(auto ss : ans){
		cout << ss << endl;
	}
	return 0;
}