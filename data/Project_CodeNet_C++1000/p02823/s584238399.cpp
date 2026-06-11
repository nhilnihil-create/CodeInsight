#include<iostream>
using namespace std;
int main(){

  long long N,A,B;
  cin>>N>>A>>B;
  if((B-A)%2==0){
  
    cout<<(B-A)/2;
    return 0;
  }
  long long ansA=A-1;
  long long ansB=N-B;
  long long ans=0;
  if(ansA<ansB){
  
    ans+=ansA+1;
    A-=ansA;
    B-=ansA+1;
    ans+=(B-A)/2;
  }
  else{
  
    ans+=ansB+1;
    B+=ansB;
    A+=ansB+1;
    ans+=(B-A)/2;
  }
  cout<<ans;
  return 0;
}