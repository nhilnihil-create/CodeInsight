#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    fastio
	ll n,t,i,j,x,k;
	cin>>n>>k;
	
	ll a[n],b[n],c;
	for(i=0;i<n;i++)
	cin>>a[i];
	
	for(i=0;i<n;i++)
	cin>>b[i];
	
	ll dp[n][5001];
	
	for(i=0;i<n;i++){
	    c=a[i];
	    dp[i][0]=0;
	    for(j=1;j<=5000;j++){
	       dp[i][j]=dp[i][j-1]+b[c-1];
	       c=a[c-1];
	    }
	}
	ll ans=-1e18;
	if(k<=5000){
	    for(i=0;i<n;i++)
	    ans=max(ans,*max_element(&dp[i][1],&dp[i][1]+k));
	}
	else{
	    vector<ll> cycle(n,1);
	    
	    for(i=0;i<n;i++){
	        c=a[i];
	        while(c!=i+1){
	            c=a[c-1];
	            ++cycle[i];
	        }
	    }
	    
	    ll mod,d;
	    for(i=0;i<n;i++){
	        d=k/cycle[i];
	        mod=k%cycle[i];
	        
	        ll l=-1e18,r=-1e18;
	        for(j=1;j<=mod;j++)
	        l=max(l,dp[i][j]);
	        for(j=1;j<=cycle[i];j++)
	        r=max(r,dp[i][j]);
	        
	        ans=max(ans,d*dp[i][cycle[i]]+l);
	        ans=max(ans,(d-1)*dp[i][cycle[i]]+r);
	        ans=max({ans,l,r});
	    }
	}
	cout<<ans;
	
	return 0;
}
