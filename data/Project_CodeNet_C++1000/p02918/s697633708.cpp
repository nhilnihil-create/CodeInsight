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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = "!" + s + "!";
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(s[i] == 'L'){
			if(s[i-1] == s[i]) ++cnt;
		}
		else{
			if(s[i+1] == s[i]) ++cnt;
		}
	}
	int ans = cnt + 2*k;
	chmin(ans, n-1);
	cout << ans << endl;
	return 0;
}