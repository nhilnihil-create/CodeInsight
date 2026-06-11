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
	ll n,m,x;cin>>n>>m>>x;
	ll c[n];
	ll a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m+1;j++){
			if(j==0){cin>>c[i];}
			else{cin>>a[i][j-1];}
		}
	}
	for(int j=0;j<m;j++){
		int c=0;
		for(int i=0;i<n;i++){
			c+=a[i][j];
		}
		if(c<x){
			cout<<-1;return;
		}
	}
	int ans=INT_MAX;
	for(int i=0;i<(1<<n);i++){
		set<int>s;int y=0;
		for(int j=0;j<n;j++){
			if((1<<j)&(i)){s.insert(j);y+=c[j];}
		}
		int arr[m]={0};
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s.count(i)){
					arr[j]+=a[i][j];
				}
			}
		}
		bool ck=true;
		for(int i=0;i<m;i++){
			if(arr[i]<x){ck=false;break;}
		}
		if(ck){ans=min(ans,y);}
	}
	cout<<((ans==INT_MAX)?-1:ans);
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
