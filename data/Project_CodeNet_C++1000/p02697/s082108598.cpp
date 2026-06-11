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
	int n, m;
	cin >> n >> m;
	vector<P> ans;
	if(n%2 == 0){
		bool ok = false;
		int l = 1, r = n-1;
		while(l < r){
			if(!ok && r-l <= n/2){
				--r;
				ok = true;
			}
			ans.emplace_back(l, r);
			++l;
			--r;
		}
	}
	else{
		int l = 1, r = n-1;
		while(l < r){
			ans.emplace_back(l, r);
			++l;
			--r;
		}
	}
	rep(i,m){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
