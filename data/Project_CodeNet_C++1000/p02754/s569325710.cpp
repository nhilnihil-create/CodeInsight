#include<bits/stdc++.h>
using namespace std;

int main(){
  long N,A,B;cin>>N>>A>>B;
  long count=0;
  long X=N/(A+B);
  count+=X*A;
  N-=X*(A+B);
  if(N<=A) count+=N;
  else count+=A;
  cout<<count<<endl;
}
  
