#include<bits/stdc++.h>
#define ll long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
using namespace std;
ll expo(ll a,ll b,ll m = mod){
	ll res = 1;
	while(b){
		if(b&1)
			res = (res*a)%mod;
		b = (b*b)%mod;
	}
	return res;
}
ll gcd(ll a,ll b){
	while(b>0){
		ll r = a%b;
		a = b; b = r;
	}
	return a;
}
//for(int i=0;i<n;i++)
int main()
{
	 
   boost
   #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t=1;
// 	cin>>t;
	while(t--)
	{
	    int l,r,d;
	    cin>>l>>r>>d;
	    cout<<r/d - (l-1)/d<<"\n";
	}
    return 0;
}
