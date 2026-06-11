#pragma GCC optimize("O4")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF (1e17)
#define int ll
#define EPS (1e-6)
#define DB(x) #x<<" "<<x<<" "
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
int fpow(int b,int p){
	b%=MOD;
	int ans=1;
	while(p>0){
		if(p&1) ans=(ans*b)%MOD;
		p/=2;
		b=(b*b)%MOD;
	}
	return ans;
}

int32_t main() {
#ifdef LOCAL_TEST
	freopen("E:\\Jimmy\\2 Coding\\1 C++\\input.in","r",stdin);
	freopen("E:\\Jimmy\\2 Coding\\1 C++\\output.out","w",stdout);
	freopen("E:\\Jimmy\\2 Coding\\1 C++\\error.out","w",stderr);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	//code...
	int n,d,a; cin>>n>>d>>a;
	vector<pii> v(n);
	for(auto &i:v) cin>>i.F>>i.S;
	sort(all(v));
	queue<pii> bang;
	int ans=0,now=0;
	for(auto &i:v){
		while(!bang.empty() && bang.front().F<i.F-d*2){
			now-=bang.front().S;
			bang.pop();
		}
		i.S=max(0ll,i.S-now*a);
		int x=(i.S+a-1)/a;
		bang.emplace(i.F,x);
		ans+=x;
		now+=x;
		//cerr<<DB(i.F)<<DB(i.S)<<DB(x)<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
