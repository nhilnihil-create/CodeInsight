#include<bits/stdc++.h>
using namespace std;
int main(){
  long H,W,A,B;cin>>H>>W>>A>>B;
  if(2*A<=W&&2*B<=H){
    for(long i=0;i<H;i++){for(long j=0;j<W;j++)cout<<((j<A)^(i<B));cout<<endl;}
  }
  else cout<<"No";
}

