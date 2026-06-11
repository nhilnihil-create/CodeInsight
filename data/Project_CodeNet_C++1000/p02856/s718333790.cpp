#include <bits/stdc++.h>
using namespace std;

int main(){
  long long M,d,c,a=0,b=0,e=0;cin>>M;
  for(int i=0;i<M;i++){
    scanf("%lld%lld",&d,&c);
    b+=d*c;
    a+=c;
  }
  while(b/10){
    a+=b/10;
    b=b%10+b/10;
  }
  cout<<--a<<endl;
}