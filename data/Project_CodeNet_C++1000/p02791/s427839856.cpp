#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
#define MOD 1000000007;
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
  
  int N;
  cin>>N;
  
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin>>P[i];
  }
  
  int ans=0;
  
  int low=P[0];
  
  
  for(int i=0;i<N;i++){
    if(P[i]<=low){
      low=P[i];
      ans++;
    }
  }
  
  cout<<ans<<endl;
}