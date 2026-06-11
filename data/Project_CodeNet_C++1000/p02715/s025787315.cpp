//#pragma GCC optimize(2) 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define clr(a,b) memset(a,b,sizeof(a))
ll n,m,k,ans;
ll f[100005];
ll mod=1000000007;
ll pow1(ll x,ll y){
	ll a=1,b=x;while(y){if(y&1)a=(a*b)%mod;b=(b*b)%mod;y>>=1;}
	return a;
}
int main(){
	//freopen("P1429_6.in","r",stdin);
	//freopen("match.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(ll i=k;i>=1;i--){
		f[i]=pow1(k/i,n);
		for(int j=2;i*j<=k;j++){
			f[i]=(f[i]-f[i*j]+mod)%mod;
		}
		ans=(ans+i*f[i])%mod;
	}
	cout<<ans<<"\n";
    return 0;
}