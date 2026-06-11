#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define all(a) a.begin(),a.end()
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define INT_INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define MOD2 1494318097
#define SEED 131
#define mp make_pair
#define fastio cin.tie(0); cin.sync_with_stdio(0);

#define MAXN 305

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unordered_map<int,int> umii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<long long>(a, b)(g1);}

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int len,K,arr[MAXN];
ll dp[MAXN][MAXN];
ll pre[MAXN][MAXN];
ll suf[MAXN][MAXN];
vector<int> vals;

int main(){
	scanf("%d %d",&len,&K);
	for(int i=1; i<=len; i++){
		scanf(" %d",&arr[i]);
		vals.pb(arr[i]);
	}
	vals.pb(0);
	sort(all(vals));
	complete_unique(vals);
	memset(dp,0x3f,sizeof dp);
	for(int i=0; i<vals.size(); i++){
		if(vals[i] == arr[1]) dp[0][i] = vals[i];
		else dp[1][i] = vals[i];
	}
	for(int ch=0; ch<=1; ch++){
		for(int c=0; c<vals.size(); c++){
			if(c == 0) pre[ch][c] = dp[ch][c]-vals[c];
			else pre[ch][c] = min(dp[ch][c]-vals[c],pre[ch][c-1]);
		}
		for(int c=(int)vals.size()-1; c>=0; c--){
			if(c == (int)vals.size()-1) suf[ch][c] = dp[ch][c];
			else suf[ch][c] = min(dp[ch][c],suf[ch][c+1]);
		}
	}
	for(int i=2; i<=len; i++){
		for(int ch=0; ch<=i; ch++){
			for(int cur=0; cur<vals.size(); cur++){
				if(vals[cur] == arr[i] && ch != i){
					ll f = pre[ch][cur]+vals[cur];
					ll s = suf[ch][cur];
					dp[ch][cur] = min(f,s);
				}else if(ch && vals[cur] != arr[i]){
					ll f = pre[ch-1][cur]+vals[cur];
					ll s = suf[ch-1][cur];
					dp[ch][cur] = min(f,s);
				}else dp[ch][cur] = LL_INF;
			}
		}
		for(int ch=0; ch<=i; ch++){
			for(int c=0; c<vals.size(); c++){
				if(c == 0) pre[ch][c] = dp[ch][c]-vals[c];
				else pre[ch][c] = min(dp[ch][c]-vals[c],pre[ch][c-1]);
			}
			for(int c=(int)vals.size()-1; c>=0; c--){
				if(c == (int)vals.size()-1) suf[ch][c] = dp[ch][c];
				else suf[ch][c] = min(dp[ch][c],suf[ch][c+1]);
			}
		}
	}
	ll res = LLONG_MAX;
	for(int ch=0; ch<=K; ch++)
		for(int v=0; v<vals.size(); v++)
			res = min(res,dp[ch][v]);
	printf("%lld\n",res);
}