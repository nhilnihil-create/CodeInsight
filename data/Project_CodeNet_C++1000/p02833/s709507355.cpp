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
	if(n%2)
		cout<<0<<endl;
	else{
		ll d=5,ans=0;
		while(d<=n){
			ans+=(n/d)/2;
			d*=5;
		}
		cout<<ans<<endl;
	}
}
