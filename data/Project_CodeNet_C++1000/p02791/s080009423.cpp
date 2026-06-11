#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
	int ml=n+1,res=0;
  
  	for(int i=0;i<n;i++){
    	int p;cin>>p;
      	ml=min(ml,p);
      if(ml==p)++res;
           
    	
    }
  cout<<res<<endl;
    
}