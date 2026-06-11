#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
int main() {
  
  long long H;
  cin>>H;
  
  long long count=1;
  
  long long ans=0;
  
  
  while(H!=0){
    H/=2;
    ans+=count;
    count*=2;
  }
  
  cout<<ans<<endl;
}