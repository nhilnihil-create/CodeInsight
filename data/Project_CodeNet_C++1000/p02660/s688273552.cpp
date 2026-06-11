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
#define dbg_v(v) cout<<#v<<":";for(auto x:v) cout<<" "<<x; cout<<endl;
int power(ll x,ll y){ll res = 1;while(y>0){if(y&1)res = (res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int gcd(int a,int b){
	if(!a)
		return b;
	return gcd(b%a,a);
}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	ll n;
	cin>>n;
	ll k=n;
	vector<int>a;
	ll sum[1000001];
	sum[0]=0;
	sum[1]=1;
	for(int i=2;i<1000001;i++)
		sum[i]=sum[i-1]+i;
	for(ll i=2;i*i<=n;i++){
		int ct=0;
		while(k%i==0){
			k/=i;
			ct++;
		}
		if(ct){
		a.pb(ct);
		}
	}
	if(k>1)
		a.pb(1);
	ll ans=0;
	for(int i=0;i<(int)a.size();i++){
		auto l=lower_bound(sum,sum+a[i],a[i]);
		if(sum[l-sum]>a[i])
			ans+=(ll)(l-sum)-1;
		else
			ans+=(ll)(l-sum);
	}
	cout<<ans<<endl;
}
