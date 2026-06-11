#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
int main() {
  
  int N,K;
  cin>>N>>K;
  
  vector<long long> H(N);
  for(int i=0;i<N;i++){
    cin>>H[i];
  }
  sort(H.begin(),H.end());
  
  long long ans=0;
  for(int i=0;i<N-K;i++){
    ans+=H[i];
  }
  
  cout<<ans<<endl;
}