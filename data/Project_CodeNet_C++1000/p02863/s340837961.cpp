#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const double eps = 1e-8;
const double pi = acos(-1.0);
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a * b / gcd(a,b);}
ll poww(ll x,ll y,ll p){ll ans = 1;while(y){if(y & 1) ans = ans * x % p;x = x * x % p;y >>= 1;}return ans % p;}
bool isp(ll x){if(x < 2) return 0; for(ll i = 2;i * i <= x;i++){if(x % i == 0) return 0;}return 1;}
int n,V,dp[3005][3005],maxw[3005],ans;
pii p[3005];
int main(){
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> V;
	rep(i,1,n) cin >> p[i].fi >> p[i].se;
	sort(p+1,p + n+1);
	for(int i = n;i >= 1;i--) maxw[i] = max(maxw[i + 1],p[i].se);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < V;j++){
			dp[i][j] = dp[i-1][j];
			if(j >= p[i].fi) dp[i][j] = max(dp[i][j],dp[i-1][j-p[i].fi] + p[i].se);
		}
		ans = max(ans,dp[i][V-1] + maxw[i + 1]);
	}
	cout << ans << endl;		
	return 0; 
}
//do smt instead of nothing! never give up!
