#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
  int n,k;
  cin>>n>>k;
  
  ll kotae=1;
  
  while(n>=k){
  	kotae++;
    n/=k;
  }
  
  cout<<kotae<<endl;
  
	
}