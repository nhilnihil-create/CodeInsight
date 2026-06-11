#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	int uh=0;
	REP(i,n-1){
		if(s[i]=='R' && s[i+1]=='L'){
			uh += 2;
		}
	}
	int rb = uh/2;
	int lb = uh/2;
	int euh=0;
	if(s[0]=='L'){
		euh++;
		lb++;
	}
	if(s[n-1]=='R'){
		euh++;
		rb++;
	}
	int ans = n-uh-euh;
	
	if(rb==lb){
		if(k >= rb){
			ans = n-1;
		}else{
			ans += k*2;
		}
	}else{
		if(k >= max(rb,lb)){
			ans = n-1;
		}else{
			ans += k*2;
		}
	}

	cout << ans << endl;
	
	
	return 0;
}