#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define inf 1e15

#define N 300005

string s;
ll n,m,x,y,d,k;
ll a[N];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int t=1;
	//cin>>t;
	while(t--){
	    
	    
	    cin>>x>>k>>d;
	    
	    if(x<0){
	        x*=-1;
	    }
	    
	    ll ans=0;
	    
	    if(k<=x/d){
	        
	        ans=x-k*d;
	    }
	    else
	    {
	        ll valr=x%d;
	        ll vall=d-x%d;
	        
	        ll used=x/d;
	        ll rem=k-x/d;
	        
	        if(rem%2==0){
	            ans=valr;
	        }
	        else
	        {
	            ans=vall;
	        }
	    }
	    
	    cout<<ans<<"\n";
	    
	    
	}
	return 0;
}
