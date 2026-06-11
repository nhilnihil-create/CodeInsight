#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
  	ll n;
  	cin>>n;
  
  	ll a[n],b[n];
  	ll all=0;
  
  	rep(i,n+1){
      cin>>a[i];

    }
  
	ll ans =0;
               
  	rep(i,n)cin>>b[i];
  
  for(int i=0;i<n;i++){
    if(a[i]<=b[i]){
        ans +=a[i];
    	b[i]-=a[i];
 
    }
    else{
    	ans +=b[i];
        b[i]=0;
    }
        
    if(a[i+1]<=b[i]){
    	ans +=a[i+1];
      	a[i+1] =0;
      	
    }
    
    else{
    	ans +=b[i];
      	a[i+1]-=b[i];

    }

  }
  
	cout<<ans<<endl;

}