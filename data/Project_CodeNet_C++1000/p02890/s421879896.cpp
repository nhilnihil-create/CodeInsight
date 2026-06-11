#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e8)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll gcd(ll a,ll b){if(!b)return a;else return gcd(b,a%b);}
int main()
{
	int n;
	cin>>n;
	vector<int>cnt(n+1),cnt1(n+1);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		cnt[a]++;
	}
	for(int i=1;i<=n;i++)cnt1[cnt[i]]++;
	vector<int>pref(n+1),prefx(n+1);
	prefx[0] = cnt1[0];
	for(int i=1;i<=n;i++)pref[i]=pref[i-1]+cnt1[i]*i;
	for(int i=1;i<=n;i++)prefx[i]=prefx[i-1]+cnt1[i];
	vector<int>f(n+1,0);
	for(int i=1;i<=n;i++){
		f[i] = (pref[i]+i*(prefx[n]-prefx[i]))/i;
	}
	vector<int>ans(n+1);
	for(int i=1;i<=n;i++){
		ans[f[i]] = max(ans[f[i]],i);
	}
	for(int i=n-1;i>0;i--)ans[i] = max(ans[i],ans[i+1]);
	for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
}

