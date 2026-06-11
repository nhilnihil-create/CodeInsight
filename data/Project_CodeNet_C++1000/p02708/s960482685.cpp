#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n,i,k,min=0,max=0,kotae=0;
  cin>>n>>k;
  n++;
  for(i=0;i<n;i++){
    min+=i+1;
    max+=n-i;
    if(i+1>=k){
      kotae+=max-min+1;
      kotae%=1000000007;
    }
  }
  cout<<kotae;
}
