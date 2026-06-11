#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mod = 1e9+7;
const ll inf = 1e18;
const double pi = 3.1415926535897932384626;

ll mpow(ll a,ll b){
    ll res=1;
    a%=mod;
    while(b){
    	if(b%2) res=res*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return res;
}

ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}

void solve(){
	//code
	ll n,m,L=1;
  	cin>>n>>m;
  	ll a[n];
  	
	for(int i=0;i<n;i++){
    	cin>>a[i];
    	a[i]/=2;
    	L=lcm(L,a[i]);
  	}
  
  	for(int i=0;i<n;i++) 
	  	if(L/a[i]%2==0){
		  	cout<<0<<endl;
			return;
		}
  	cout<<m/(2*L)+(m%(2*L)>=L ? 1 : 0)<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
 	return 0;
}
