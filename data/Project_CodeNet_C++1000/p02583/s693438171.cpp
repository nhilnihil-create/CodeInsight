#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define inf 1e15

#define N 300005

string s;
int n,m,x,y;
int a[N];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int t=1;
//	cin>>t;
	while(t--){
	    
	    
	    cin>>n;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    sort(a,a+n);
	    
	    ll ans=0;
	    
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            for(int k=j+1;k<n;k++){
	                
	                if(a[i]!=a[j] && a[j]!=a[k]){
	                    
	                    if(a[i]+a[j]>a[k]){
	                        
	                       // cout<<i+1<<" "<<j+1<<" "<<k+1<<" %\n";
	                        ans++;
	                    }
	                }
	                
	            }
	        }
	    }
	    
	    cout<<ans<<"\n";
	    
	    
	}
	return 0;
}
