#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int ans[100005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size(), cnt = 0;
	rep(i,n){
		if(s[i] == 'R') ++cnt;
		else{
			ans[i] += cnt / 2;
			ans[i-1] += cnt - cnt / 2;
			cnt = 0;
		}
	}
	cnt = 0;
	for(int i = n-1; i >= 0; --i){
		if(s[i] == 'L') ++cnt;
		else{
			ans[i] += cnt / 2;
			ans[i+1] += cnt - cnt / 2;
			cnt = 0;
		}
	}
	rep(i,n-1) cout << ans[i] << " " ;
	cout << ans[n-1] << endl;
	return 0;
}
