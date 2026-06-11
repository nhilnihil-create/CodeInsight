#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(int i=0;i<(int)v.size();i++) cout<<" "<<v[i]; cout<<endl;
int gcd(ll a,ll b){
	if(!a)
		return b;
	return gcd(b%a,a);
}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int t=1;
	//cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll a[n];
		ll lc;
		cin>>a[0];
		a[0]/=2;
		lc=a[0];
		int f=0;
		for (int i = 1; i < n; i++)
		{
			cin>>a[i];
			a[i]/=2;
		}
		ll mx=-1e18;
		for(int i=1;i<n;i++){
			ll gc=gcd(lc,a[i]);
			lc=((lc/gc)*a[i]);
			mx=max(lc,mx);
			if(lc>m||lc<mx){
				f=1;
				break;
			}
		}
		if(f)
			cout<<0<<endl;
		else{
			f=0;
			for(int i=0;i<n;i++){
				if(lc/a[i]%2==0)
					f=1;
			}
			if(f)cout<<0<<endl;
			else{
			ll ans=(m/lc+1LL)/2LL;
			cout<<ans<<endl;
		}
		}
	}
}

