#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define testing 1
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
#define IAMSPEED ios_base::sync_with_stdio(false); cin.tie(0);
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << " , " << #y << "=" << y << endl
#define db3(a,b,c) cerr<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c<<endl
#define dbv(v) cerr << #v << ":"; for (auto it : v) cerr << it << ' '; cerr << endl
#define dbvp(v) cerr << #v << ":"; for (auto it : v) cerr << "{"  << it.f << ',' << it.s << "} "; cerr << endl
#define dba(a,ss,ee) cerr << #a << ":"; FOR(i,ss,ee) cerr << a[i] << ' '; cerr << endl
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long 
#define pb push_back
#define inf (int)1e9+500
#define oo (ll)1e18+500
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define reach cerr << "LINE: " << __LINE__ << "\n";
typedef pair <int, int> pi;
typedef pair <ll,ll> pl;
typedef pair <pi, int> pii;
typedef tuple<int,int,int> ti3;
string cts(char x) {string t(1,x); return t;}
ll rand(ll a, ll b) { return a + rng() % (b-a+1); }
const int MOD = 1e9 + 7;
template <typename T> void chmax(T& a, T b) {
	a = max(a, b);
}
template <typename T> void chmin(T& a, T b) {
	a = min(a, b);
}
#define MAXN (int)1e6+5
#if !testing
#define cerr if(0)cout
#endif
string str;
ll dp[MAXN][2];
int32_t main() {
	IAMSPEED
	cin>>str;
	dp[0][1] = 1;
	int n = str.size();
	str = "A"+str;
	FOR(i,1,str.size()-1) {
		if(str[i]=='1') {
			dp[i][0]+=dp[i-1][0]*3+dp[i-1][1];
			dp[i][1]+=dp[i-1][1]*2;
		} else {
			dp[i][0]+=dp[i-1][0]*3;
			dp[i][1]+=dp[i-1][1];
		}
		dp[i][0]%=MOD;
		dp[i][1]%=MOD;
	}
	cout<<(dp[n][0]+dp[n][1])%MOD;
	
}
