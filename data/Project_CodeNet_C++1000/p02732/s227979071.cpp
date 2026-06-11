#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define PI 3.1415926535897932
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
long long LCM(long long A,long long B){
  long long g=GCD(A,B);
  return A/g*B;
}
long long num_order(long long X){
  long long ans=0;
  while(true){
    if(X==0){
      break;
    }
    else{
      X/=10;
      ans++;
    }
  }
  return ans;
}
int main() {
  
  long long N;
  cin>>N;
  
  vector<long long> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  vector<long long> app(200000);
  for(int i=0;i<N;i++){
    app[A[i]-1]++;
  }
  
  
  long long sum=0;
  for(int i=0;i<200000;i++){
    sum+=(app[i]*(app[i]-1)/2);
  }
  
  
  for(int i=0;i<N;i++){
    cout<<sum-(app[A[i]-1]-1)<<endl;
  }
}