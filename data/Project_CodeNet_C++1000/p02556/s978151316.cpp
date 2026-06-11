#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mod 1000000007
#define vll vector<ll>
#define inf 1e18
#define pll pair<ll,ll>
#define ff first 
#define ss second 
#define PI acos(-1)
using namespace std;
ll binpow(ll x, ll y) {
    ll int res = 1;
    for(int i = 1; i <= y; i++) {
        res = (res * x) % mod;
    }
    return res;
} 
int main() 
{
    fastio; 
    ll T=1;
    //cin>>T; 
    while(T--)
    { 	
    ll n;
	cin>>n;
	
    ll f[4][n];
    
    for(int i=0;i<n;++i)
    {
    	int x,y;
    	cin>>x>>y;
    	f[0][i]= x+y;
    	f[1][i]= x-y;
    	f[2][i]=-x+y;
    	f[3][i]=-x-y;
    }
    
    for(int i=0;i<4;++i)
    {
    	sort(f[i],f[i]+n);
    }
    
    ll mx=-1;
    
    for(int i=0;i<4;++i)
    mx=max(mx,abs(f[i][0]-f[i][n-1]));
	
	cout<<mx<<endl;
	}
}
 