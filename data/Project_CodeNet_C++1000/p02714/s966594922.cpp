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
	string s;
	cin >> n >> s;
	set<int> R, G, B;
	rep(i,n){
		if(s[i] == 'R') R.insert(i);
		if(s[i] == 'G') G.insert(i);
		if(s[i] == 'B') B.insert(i);
	}
	ll ans = 0;
	for(int r : R){
		for(int g : G){
			int i = min(r, g) - abs(r - g);
			int j = (r + g) / 2;
			if((r + g)%2 != 0) j = -1;
			int k = max(r, g) + abs(r - g);
			ans += B.size();
			if(0 <= i && s[i] == 'B') --ans;
			if(0 <= j && j < n && s[j] == 'B') --ans;
			if(k < n && s[k] == 'B') --ans;
		}
	}
	cout << ans << endl;
	return 0;
}
