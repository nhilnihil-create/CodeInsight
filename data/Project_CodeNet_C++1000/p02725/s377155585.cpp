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
void solve(){
	ll m,n;
	cin>>m>>n;
	ll a[n];
	for(int i=0;i<n;i++){cin>>a[i];}
	int sum=m-a[n-1]+a[0];
	for(int i=1;i<n;i++){
		sum+=(a[i]-a[i-1]);
	}
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if(i==0){
			ans=min(ans,sum-(a[i+1]-a[i]));
			ans=min(ans,sum-(m-a[n-1]+a[0]));
		}
		else if(i==n-1){
			ans=min(ans,sum-(a[i]-a[i-1]));
			ans=min(ans,sum-(m-a[n-1]+a[0]));
		}
		else{
			ans=min(ans,sum-(a[i]-a[i-1]));
			ans=min(ans,sum-(a[i+1]-a[i]));
		}
	}
	cout<<ans;
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
