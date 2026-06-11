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
	vector<string> s(n);
	vector<int> t(n);
	rep(i,n) cin >> s[i] >> t[i];
	string x;
	cin >> x;
	int ans = 0;
	bool flag = false;
	rep(i,n){
		if(flag) ans += t[i];
		if(s[i] == x) flag = true;
	}
	cout << ans << endl;
	return 0;
}
