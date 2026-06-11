#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
  if(y==0){
    return x;
  }
  return gcd(y,x%y);
}
int main(){
  int k;
  cin>>k;
  long long ans=0;
  for(int a=1;a<=k;a++){
    for(int b=1;b<=k;b++){
      for(int c=1;c<=k;c++){
        int tmp=gcd(a,b);
        ans+=gcd(tmp,c);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
      