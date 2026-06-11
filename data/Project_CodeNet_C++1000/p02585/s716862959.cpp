#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define fill(a,b) memset(a,b,sizeof(a))
#define f first
#define s second

#define inf 1e15
#define ninf -1*1e15
#define mod 1000000007
#define N 500005
#define Ns 5005

string s;
ll n,m,x,y,d,k;
ll a[N],p[N],c[N],cost[N];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int t=1;
//	cin>>t;
	while(t--){
	    
	    
	    cin>>n>>k;
	    for(int i=0;i<n;i++){
	        cin>>p[i];
	        p[i]--;
	    }
	     for(int i=0;i<n;i++){
	        cin>>c[i];
	        
	    }
	    ll ans=ninf;
	    
	    for(int i=0;i<n;i++){
	        
	        ll len=0,total=0;
	        
	        int j=p[i];
	        
	        while(j!=i){
	            total+=c[j];
	            cost[len++]=total;
	            j=p[j];
	        }
	        
	        total+=c[i];
	        cost[len++]=total;
	        
	        
	        if(k<=len){
	            
	            ll cnt=ninf;
	            
	            for(int j=0;j<k;j++){
	               
	                cnt=max(cnt,cost[j]);
	            }
	          
	            ans=max(ans,cnt);
	        }
	        else
	        {
	            ll mx=ninf,mx2=ninf;
	            
	            for(int j=0;j<len;j++){
	                mx=max(mx,cost[j]);
	            }
	           
	             for(int j=0;j<k%len;j++){
	                 mx2=max(mx2,cost[j]);
	             }
	            
	            
	            ll h=k/len;
	            
	            ans=max(ans,mx);
	            ans=max(ans,mx+total*(h-1));
	            ans=max(ans,mx2+total*(h));
	        }
	    }
	    
	    
	    
	    
	    cout<<ans<<"\n";
	    
	    
	}
	return 0;
}
