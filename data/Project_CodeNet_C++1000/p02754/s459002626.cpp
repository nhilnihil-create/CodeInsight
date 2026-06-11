#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long n,a,b; cin>>n>>a>>b;
  long long res=0;
  if(a>0){
    res=n/(a+b)*a;
    n-=n/(a+b)*(a+b);
    res+=min(n,a);
  }
  cout<<res;
  return 0;
}
    
