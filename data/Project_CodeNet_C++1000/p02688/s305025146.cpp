#include <bits/stdc++.h>
using namespace std;
#define ff        first
#define ss        second
#define ll        long long
#define int        long long
#define inf       ((ll)1e18)
#define double    long double
#define ull       unsigned long long
#define mod       1000000007
#define vi        vector<ll>
#define extreme   inline
#define ppi       pair<ll,pair<ll,ll>>
#define pb        push_back
#define mp        make_pair
#define pi        2*acos(0.0)
bool cust(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);} 
#define pr(a,x,y) for(int i=x;i<y;i++){cout<<a[i]<<" ";}
#define p(a)      cout<<a;
#define sp(x,y)   fixed<<setprecision(y)<<x
#define w(x)      ll x; cin>>x; while(x--)
#define all(v)    v.begin(), v.end()
#define rall(v)   v.rbegin(), v.rend()
#define test      cout<<"THIS_AND_THIS"<<endl;
#define str       string
void kehsihba(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
}
void solve(){
	ll n,k;
	cin>>n>>k;
	map<ll,ll>m;
	for(int i=0;i<k;i++){
		ll y;cin>>y;
		for(int j=0;j<y;j++){
			ll a;cin>>a;
			m[a]+=1;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(m[i]){continue;}
		else{ans+=1;}
	}
	cout<<ans;
}
int32_t main(){
	kehsihba();
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}