#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod = 2019;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> cnt(n+1, 0);
	int ten = 1;
	for(int i = n-1; i >= 0; --i){
		int num = ((s[i] - '0') * ten) % mod;
		cnt[i] = (cnt[i+1] + num) % mod;
		ten = (ten * 10) % mod;
	}
	ll ans = 0;
	map<int, ll> mp;
	for(int i = n; i >= 0; --i){
		ans += mp[cnt[i]]++;
	}
	cout << ans << endl;
	return 0;
}