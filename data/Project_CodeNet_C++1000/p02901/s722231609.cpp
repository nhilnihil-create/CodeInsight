#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define mp make_pair
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(s) s.begin(),s.end()
#define vll vector<ll>
#define vi vector<int>
#define vpii vector<pii>
#define vpll vector<pll>
#define vd vector<double>
#define vull vector<ull>
#define vc vector<char>
#define vs vector<string>
#define fi first
#define se second
#define sz(x) x.size()
#define cinarr(n,a) for(int i = 0; i < n; i++) cin >> a[i];
#define coutarr(n,a) for(int i = 0; i < n; i++) cout << a[i] << (i+1==n?'\n':' ');
#define fori(i,a,b,x) for(int i = a; i <= b; i+=x)
#define ford(i,a,b,x) for(int i = a; i >= b; i-=x)
#define tc int tt; cin >> tt; for(int cs = 1; cs <= tt; cs++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ld long double
#define reset(x,y) memset(x,y,sizeof x);
#define sqr(x) 1LL*(x)*(x)
#define cube(x) 1LL*(x)*(x)*(x)
#define ub(v, a) upper_bound(all(v), a)
#define lb(v, a) lower_bound(all(v), a)
#define EPS 1e-10
#define INF 200000
#define mod 1000000007
#define minof(a) min_element(all(a))
#define maxof(a) max_element(all(a))
#define debug(val) cerr << "The value of " << #val << " is = " << val << endl;
#define testing cerr << "--------------------------\n";

ll dp[1<<15][1005];
ll a[1005],b[1005],mask[1005],n,m;

ll f(ll msk, ll nw) {
	if(nw==m) {
//		debug(nw)
//		debug(m)
		return (msk==(1<<n)-1?0:mod);
	}
//	debug(dp[msk][nw])
	if(dp[msk][nw]!=-1) return dp[msk][nw];
//	debug(msk)
//	debug(nw)
	return dp[msk][nw]=min(f((msk|mask[nw]),nw+1)+a[nw],f(msk,nw+1));
}

int main() {
	IOS
	reset(dp,-1);
	cin>>n>>m;
	for(int i = 0; i < m; i++) {
		cin>>a[i]>>b[i];
		for(int j = 0,x; j < b[i]; j++) {
			cin>>x;
			x--;
			mask[i]|=(1<<x);
		}
	}
	ll res=f(0,0);
	cout<<(res==mod?-1:res)<<endl;
}
