#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
  	ll h[n];
  	rep(i,n)cin>>h[i];
  
  	bool ans=true;

  	for(int j=1;j<n;j++){
      	if(h[j-1]<h[j]){
        h[j]--;
        }
    	if(h[j-1]>h[j]){
        	ans=false;
          	break;
        }
      

    
    }
  
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}