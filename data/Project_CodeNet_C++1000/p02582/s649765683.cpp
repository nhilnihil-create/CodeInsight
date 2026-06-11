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
	    
	    
	    cin>>s;
	   
	    ll ans=0,cnt=0;
	   
	    for(int i=0;s[i];i++){
	        
	        if(s[i]=='R'){
	            cnt++;
	            
	        }
	        else
	        {
	            ans=max(ans,cnt);
	            cnt=0;
	        }
	    }
	    ans=max(ans,cnt);
	    
	    cout<<ans<<"\n";
	    
	    
	}
	return 0;
}
