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
	int n, m; cin >> n >> m;
	VI a(n), b(m);
	REP(i,n) cin >> a[i];
	REP(i,m) cin >> b[i];
	VVI dp(n,VI(m,0)), s(n,VI(m,0));
	REP(i,n)REP(j,m){
		if(i>0)
			s[i][j]+=s[i-1][j];
		if(j>0)
			s[i][j]+=s[i][j-1];
		if(i>0&&j>0)
			s[i][j]-=s[i-1][j-1];
		s[i][j]=(s[i][j]+2*MOD)%MOD;
		if(a[i]==b[j]){
			if(i>0&&j>0)
				dp[i][j]=s[i-1][j-1]+1;
			else
				dp[i][j]=1;
			dp[i][j]%=MOD;
			s[i][j]+=dp[i][j];
		}
		s[i][j]%=MOD;
	}
	ll ans=0;
	REP(i,n)REP(j,m)
		ans=(ans+dp[i][j])%MOD;
	cout << (ans+1)%MOD << endl;
	return 0;
}
