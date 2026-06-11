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
	map<char, int> mp;
	rep(i,4){
		++mp[s[i]];
	}
	if(mp.size() == 2 && mp[s[0]] == 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
