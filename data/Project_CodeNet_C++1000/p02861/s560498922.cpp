
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e6+3)
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
ld eval(ll x,ll y,ll x1,ll y1)
{
	ld r = (x-x1);
	ld r1 = (y-y1);
	return sqrt(r*r+r1*r1);
} 
int main()
{
	ld n;
	cin>>n;
	vector<ld>x(n),y(n);
	for(int i=0;i<n;i++)cin>>x[i]>>y[i];
	ld ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			if(i == j)continue;
			ld res = eval(x[i],y[i],x[j],y[j]);
			res/=n;
			ans+=res;
		}
	}
	ld p = 1;
	cout<<fixed<<setprecision(10)<<ans;
}

