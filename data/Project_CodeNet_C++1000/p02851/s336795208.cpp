#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 998244353;
const ll INF = 4611686018427387903;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main(){
	int n, k; cin >> n >> k;
	VI a(n); REP(i,n) cin >> a[i];
	VI s(n+1); s[0]=0;
	REP(i,n){
		s[i+1]=s[i]+a[i]-1+k;
		s[i+1]%=k;
	}
	map<ll,ll> mp;
	ll ans=0;
	REP(i,n+1){
		if(i>=k)
			mp[s[i-k]]--;
		ans+=mp[s[i]];
		mp[s[i]]++;
	}
	cout << ans << endl;
	return 0;
}
