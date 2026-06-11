#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653

int main(){
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	ll cntlr = 0;
	ll cntrl = 0;
	ll ans = 0;
	FOR(i,1,n){
		if (s[i-1]=='L'&&s[i]=='R') cntlr++;
		else if (s[i-1]=='R'&&s[i]=='L') cntrl++;
		else if (s[i-1]=='L'&&s[i]=='L') ans++;
		else if (s[i-1]=='R'&&s[i]=='R') ans++;
	}
	if (cntrl>cntlr){
		if (cntlr>=k){
			cout << ans+2*k << endl;
		}
		else if (s[0]=='R'||s[n-1]=='L'){
			cout << ans+2*cntlr+1 << endl;
		}
		else{
			cout << ans+2*cntlr << endl;
		}
	}
	else if (cntlr>cntrl){
		if (cntrl>=k){
			cout << ans+2*k << endl;
		}
		else if (s[0]=='L'||s[n-1]=='R'){
			cout << ans+2*cntrl+1 << endl;
		}
		else{
			cout << ans+2*cntlr << endl;
		}
	}
	else{
		if (cntlr>=k){
			cout << ans+2*k << endl;
		}
		else{
			cout << ans+2*cntlr << endl;
		}
	}
}