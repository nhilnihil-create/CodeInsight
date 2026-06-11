#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	ll k;
	cin >> s >> k;
	int n = s.size();
	int p = 0;
	char b = s[0];
	vector<int> cnt(n+1, 0);
	rep(i,n){
		if(s[i] == b) cnt[p]++;
		else{
			cnt[++p]++;
			b = s[i];
		}
	}
	if(p == 0){
		cout << n * k / 2 << endl;
		return 0;
	}
	ll ans = 0;
	rep(i,p+1) ans += cnt[i]/2;
	ans *= k;
	if(s[0] == s[n-1]) ans -= (cnt[0]/2 + cnt[p]/2 - (cnt[0] + cnt[p]) / 2) * (k - 1);
	cout << ans << endl;
	return 0;
}