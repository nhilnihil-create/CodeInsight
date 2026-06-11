#include <bits/stdc++.h>
using namespace std;


int main(){
  int64_t N, A, B;
  cin>>N>>A>>B;

  int64_t ans=N/(A+B)*A;
  int64_t amari = N%(A+B);
  if(amari<=A){
    ans += amari;
  }
  else{
    ans += A;
  }
  
  cout<<ans<<endl;
  
}