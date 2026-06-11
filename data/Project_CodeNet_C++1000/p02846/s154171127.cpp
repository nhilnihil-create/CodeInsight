#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n,t1,t2,a1,a2,b1,b2,sa1,sa2,kotae;
  cin>>t1>>t2>>a1>>a2>>b1>>b2;
  sa1=a1*t1-b1*t1;
  sa2=a2*t2-b2*t2+sa1;
  if(sa1>0&&sa2>0){
    cout<<0;
    return 0;
  }
  if(sa1<0&&sa2<0){
    cout<<0;
    return 0;
  }
  if(sa2==0){
    cout<<"infinity";
    return 0;
  }
  sa1=abs(sa1);
  sa2=abs(sa2);
  kotae=sa1/sa2*2+1;
  if(sa1%sa2==0){
    kotae--;
  }
  cout<<kotae;
}
