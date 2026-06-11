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

int main(){
	ll n; cin >> n;
	string s; cin >> s;
	ll ans = 0;
	ll i = n-1;
	while (i>=ans){
		ll j = 0; ll cnt = 0;
		while((i+j<=n-1)&&(cnt<i)){
			if (s.at(j)==s.at(j+i)){
				cnt++;
				ans=max(cnt,ans);
			}
			else{
				ans=max(cnt,ans);
				cnt = 0;
			}
			//cout << j << " " << i+j << " " << cnt << endl;
			j++;
		}
		i--;
	}
	cout << ans << endl;
}