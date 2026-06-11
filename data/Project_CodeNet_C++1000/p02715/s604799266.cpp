#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define debug4(x,y,z,w) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#w<<" :: "<<w<<endl;


ll add(ll a,ll b){
    return (a + b) % mod;
}

ll mul(ll a,ll b){
	return a * b % mod;
}

ll sub(ll a,ll b){
	ll ans = (a - b) % mod;
	if(ans<0) ans+=mod;
	return ans;
}

const int inf = 1e6;
int main()
{  
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    
    auto p=[&](ll a,ll b){
		ll an=1;
		while(b>0){
			if(b&1)an=mul(an,a);
			b>>=1;
			a=mul(a,a);
		}
		return an;
	};
    
    vector<ll> v(k+1);
    
    for(int i=k;i>0;i--){
		ll ans=0;
		ans=add(ans,p((k/i),n));
		for(int j=2*i;j<=k;j+=i){
			ans=sub(ans,v[j]);
		}
		v[i]=ans;
		//debug2(i,v[i]);
	}
	
	ll sum=0;
	for(int i=1;i<=k;i++){
		sum=add(sum,mul(i,v[i]));
	}
	cout<<sum<<"\n";	
   
}

