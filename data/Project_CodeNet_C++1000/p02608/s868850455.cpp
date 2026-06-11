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
	    int n;
	    cin>>n;
	    int ans[n+1];
	    int s = sqrt(n);
	    
	    memset(ans,0,sizeof(ans));
	    for(int i=1;i<=s;i++){
	        for(int j=1;j<=s;j++){
	            for(int k=1;k<=s;k++){
	                int sum = i*i + j*j + k*k + i*j + j*k + k*i;
	                if(sum<=n)
	                ans[sum]++;
	            }
	        }
	    }
	    for(int i=1;i<=n;i++)
	    cout<<ans[i]<<"\n";
	}
    return 0;
}
