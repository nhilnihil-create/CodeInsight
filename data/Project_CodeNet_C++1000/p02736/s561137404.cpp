#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 4611686018427387903;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main(){
	int n; cin >> n;
	string s; cin >> s;
	VI a(n); bool f=0;
	REP(i,n){
		a[i]=s[i]-'0';
		if(a[i]==2)
			f=1;
	}
	ll ans=0;
	if(f){
		REP(i,n){
			if(a[i]==2)
				ans+=(i==(i&n-1));
			ans%=2;
		}
		cout << ans << endl;
	}
	else{
		REP(i,n){
			if(a[i]==3)
				ans+=(i==(i&n-1));
			ans%=2;
		}
		cout << ans*2 << endl;
	}
	return 0;
}