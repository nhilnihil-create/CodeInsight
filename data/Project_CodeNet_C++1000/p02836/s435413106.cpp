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
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	rep(i,n/2){
		if(s[i] != s[n-1-i]) ++ans;
	}
	cout << ans << endl;
	return 0;
}