#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(int i=0;i<(int)v.size();i++) cout<<" "<<v[i]; cout<<endl;
int power(ll x,ll y){ll res = 1;while(y>0){if(y&1)res = (res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int t=1;
	//cin>>t;
	while(t--){
		int x,y,a,b,c;
		cin>>x>>y>>a>>b>>c;
		int red[a],green[b];
		vector<int>col;
		for (int i = 0; i < a; i++)
		{
			cin>>red[i];
		}
		for (int i = 0; i < b; i++)
		{
			cin>>green[i];
		}
		for (int i = 0; i < c; i++)
		{	
			int v;
			cin>>v;
			col.pb(v);
		}
		sort(red,red+a);
		reverse(red,red+a);
		sort(green,green+b);
		reverse(green,green+b);
		for (int i = 0; i < x; i++)
		{
			col.pb(red[i]);
		}
		for (int i = 0; i < y; i++)
		{
			col.pb(green[i]);
		}
		sort(all(col));
		ll ans=0;
		reverse(all(col));
		for(int i=0;i<x+y;i++)	
			ans+=(ll)col[i];
		cout<<ans<<endl;
	}
}
