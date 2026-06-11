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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(n+1, 0), b(n+1, 0);
	int cnt = 0;
	rep(i,n){
		if(s[i] == '<') ++cnt;
		else cnt = 0;
		a[i+1] = cnt;
	}
	cnt = 0;
	for(int i = n-1; i >= 0; --i){
		if(s[i] == '>') ++cnt;
		else cnt = 0;
		b[i] = cnt;
	}
	ll ans = 0;
	rep(i,n+1) ans += max(a[i], b[i]);
	cout << ans << endl;
	return 0;
}
