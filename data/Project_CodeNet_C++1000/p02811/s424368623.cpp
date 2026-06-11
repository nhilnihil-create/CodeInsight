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

void solve(){
	//code
	int n,x;
	cin>>n>>x;
	if(n*500>=x) cout<<"Yes";
	else cout<<"No";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
 	return 0;
}
