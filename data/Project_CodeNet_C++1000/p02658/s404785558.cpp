#include<bits/stdc++.h>
using namespace std;

//#define ulong unsigned long

int main(){
  long N;cin>>N;
  long S=1000000000000000000;
  vector<long> A(N);
  bool can=true;
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    if(A.at(i)==0) can=false;
  }
  
  long ans=1;
  for(int i=0;i<N;i++){
    if(S/ans>=A.at(i)) ans*=A.at(i);
    else{
      ans=-1;
      break;
    }
  }
  if(!can) ans=0;
  cout<<ans<<endl;
}
    
