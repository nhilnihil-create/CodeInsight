#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pie 3.1415926536
#define pb push_back
#define N 1000000007
#define M 998244353
#define ff first
#define ss second
#define INF 1ll<<63 - 1
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define nrep(i,a,b) for(int i=a;i>=b;i--)
#define pl pair<ll,ll>
#define pi pair<int,int>
#define pll pair<pair<ll,ll>, ll> 
#define pii pair< int, pair<int,int> >
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1; 
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
ll aa[300005];
ll dp[300005][60];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t,x,y,q,z,k,n,m,xx,yy;
    cin>>n;
    rep(i,1,n){
    	cin>>aa[i];
	}
	nrep(i,n,1){
		rep(j,0,59){
			dp[i][j] = dp[i+1][j];
			if((1ll<<j)&aa[i]) dp[i][j]++;
		}
	}
	ll ans = 0;
	rep(i,1,n){
		rep(j,0,59){
			z = n - i;
			if((1ll<<j)&aa[i]){
				z -= dp[i+1][j];
				ans = (ans%N  + (z*power(2,j,N))%N)%N;
			}else{
				z = dp[i+1][j];
				ans = (ans%N  + (z*power(2,j,N))%N)%N;
			}
		}
	}
	cout<<ans;
}