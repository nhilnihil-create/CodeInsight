#include <bits/stdc++.h>
using namespace std;
#define ff        first
#define ss        second
#define ll        long long
#define int       long long
#define inf       ((ll)1e18)
#define mod       1000000007
#define double    long double
#define ull       unsigned long long
#define vi        vector<ll>
#define ppi       pair<int,int>
#define pii       pair<pair<int,int>,int>
#define pb        push_back
#define pi        2*acos(0.0)
#define rev       greater<int>()
#define pr(a,x,y) for(int i=x;i<y;i++){cout<<a[i]<<" ";}
#define ps(s)     for(auto i:s){cout<<i<<" ";}
#define sp(x,y)   fixed<<setprecision(y)<<x
#define w(x)      ll x; cin>>x; while(x--)
#define all(v)    v.begin(), v.end()
#define rall(v)   v.rbegin(), v.rend()
#define test      cout<<"This is test"<<endl;
#define str       string
#define endl      '\n'
#define e         cout<<'\n';
void kehsihba(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
}
double get(pair<int,int>a,pair<int,int>b){
	int x=a.ff-b.ff;
	int y=a.ss-b.ss;
	x=x*x;y=y*y;
	return (double)sqrt(x+y);
}
void solve(){
	ll n;cin>>n;
	vector<pair<int,int>>v;
	vi a(n);
	int md=1;
	for(int i=0;i<n;i++){
		ll x,y;cin>>x>>y;
		v.pb({x,y});
		a[i]=i;
		md*=(i+1);
	}
	double ans=0;
	do{
		for(int i=1;i<n;i++){
			ans+=get(v[a[i]],v[a[i-1]]);
		}
	}while(next_permutation(all(a)));
	cout<<sp((double)ans/md,10);
}
int32_t main(){
	kehsihba();
	//init();
	ll t=1;
	//cin>>t;
	for(int k=1;k<=t;k++){
		//cout<<"Case "<<k<<": ";
		solve();
		//e;
	}
}