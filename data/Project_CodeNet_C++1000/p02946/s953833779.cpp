#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int k,x;
  	cin>>k>>x;
  
  	x+=1000000;
      
      
  
  for(int i=0;i<=2000000;i++){
    if(i>x-k&&i<x+k) {
    	cout<<i-1000000<<" ";
    }
  }
  	
}