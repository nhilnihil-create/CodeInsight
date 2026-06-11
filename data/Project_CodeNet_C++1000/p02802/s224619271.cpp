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
	ll n,me;cin>>n>>me;
	ll m[n+1]={0};
	ll b[n+1]={0};
	for(int i=0;i<me;i++){
		str s;int a;
		cin>>a>>s;
		if(s=="AC"){
			m[a]=1;
		}
		else{
			if(!m[a]){
				b[a]+=1;
			}
		}
	}
	int r1=0,r2=0;
	for(int i=1;i<=n;i++){
		r1+=m[i];
		if(m[i]){
		r2+=b[i];}
	}
	cout<<r1<<" "<<r2;
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