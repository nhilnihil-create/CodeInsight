#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M,A,ben=0;
  cin>>N>>M;
  for(int i=0;i<M;i++){
    cin>>A;
    ben+=A;
  }
  
  if(N-ben<0) cout<<"-1";
  else   cout<<N-ben;
  
  
  return 0;
}
