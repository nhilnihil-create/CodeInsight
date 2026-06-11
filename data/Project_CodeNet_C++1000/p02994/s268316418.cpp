#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
  int n,l;
  cin>>n>>l;
  
  int pie=0;
  
  if(l>0){
  	for(int i=1;i<n;i++){
    	pie+=l+i;
    }
  }
  
  else if(l<=0&&n+l>0){
  	for(int i=0;i<n;i++){
    	pie+=l+i;
    }
  }
  
  else{
  	for(int i=0;i<n-1;i++){
    	pie+=l+i;
    }
  }
  
  cout<<pie<<endl;
	
}