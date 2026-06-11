#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N,A,B;cin>>N>>A>>B;
  if((B-A)%2==0){
    cout<<(B-A)/2<<endl;
  }
  else{
    if(A>N-B){
      cout<<(N-A+N-B+1)/2<<endl;
    }
    else{
      cout<<(A-1+B-1+1)/2<<endl;
    }
  }
}