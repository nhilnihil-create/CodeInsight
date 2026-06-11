#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll  long long
#define all(v) (v.begin(),v.end())
#define ff first
#define ss second

const ll mod=1e9+7;
ll bin(ll a, ll b) {
	a%=mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod; //mod
        a = a * a % mod; //mod
        b >>= 1;
    }
    return res%mod;
}
int main()
{
	fast;
	ll n,k,i,j;
	ll a[100005];
	cin>>n>>k;
	ll fans=0;
	for(i=k;i>=1;--i){
	
		a[i]=bin(k/i,n);
		
		for(j=2*i;j<=k;j+=i){
			a[i]=(a[i]-a[j]+mod)%mod;
		}
		fans=(fans+a[i]*i)%mod;
		
	}
	cout<<fans;
}