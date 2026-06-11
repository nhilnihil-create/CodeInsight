#include<bits/stdc++.h>
#define de(x) cout<<#x<<"="<<x<<endl
#define dd(x) cout<<#x<<"="<<x<<" "
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define repd(i,a,b) for(int i=a;i>=(b);--i)
#define repp(i,a,b,t) for(int i=a;i<(b);i+=t)
#define mt(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp(u,v) make_pair(u,v)
#define sz(a) (int)a.size()
#define pb push_back
#define PI acos(-1.0)
#define qc std::ios::sync_with_stdio(false)
#define all(a) a.begin(),a.end()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

const ll mod = 1000000007;
const int N = 2e3+6;
const int M = 2e6+6;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;

bool eq(const db &a, const db &b) { return fabs(a - b) < eps; }
bool ls(const db &a, const db &b) { return a + eps < b; }
bool le(const db &a, const db &b) { return eq(a, b) || ls(a, b); }
ll gcd(ll a,ll b) { return a==0?b:gcd(b%a,a); };
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll kpow(ll a,ll b) {ll res=1;a%=mod; if(b<0) return 1; for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll read(){
    ll x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//inv[1]=1;
//for(int i=2;i<=n;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
int n, m;
ll dp[N][N];
void init() {
	mt(dp, 0);
}
int s[N], t[N];
int main() {
	// dp[i][j] 表示以s[i]和t[j]结尾的相同子序列的个数
	// 到后面就是前缀和了
	while(~scanf("%d%d", &n, &m)) {
		init();
		rep(i, 1, n + 1) scanf("%d", s + i);
		rep(i, 1, m + 1) scanf("%d", t + i);
		rep(i, 1, n + 1) rep(j, 1, m + 1) {
			if(s[i] != t[j]) dp[i][j] = 0;
			else {
				dp[i][j] = (dp[i-1][j-1] + 1) % mod;
			}
			// dd(i), dd(j), de(dp[i][j]);
			dp[i][j] += (dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]);
			dp[i][j]  = (dp[i][j] + mod) % mod;
		}
		printf("%lld\n", (dp[n][m] + 1) % mod);
	}
    return 0;
}
