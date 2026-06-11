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
	int n, k;
	cin >> n >> k;
	ll r, s, p;
	cin >> r >> s >> p;
	string t;
	cin >> t;
	ll ans = 0;
	rep(i,n){
		if(t[i] == 'r'){
			if(i-k < 0 || t[i-k] != 'r') ans += p;
			else t[i] = '!';
		}
		else if(t[i] == 's'){
			if(i-k < 0 || t[i-k] != 's') ans += r;
			else t[i] = '!';
		}
		else{
			if(i-k < 0 || t[i-k] != 'p') ans += s;
			else t[i] = '!';
		}
	}
	cout << ans << endl;
	return 0;
}