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
  
  int N,K;
  cin>>N>>K;
  
  vector<double> P(N);
  for(int i=0;i<N;i++){
    cin>>P[i];
  }
  
  vector<double> exp(N);
  for(int i=0;i<N;i++){
    exp[i]=(P[i]+1)/2;
  }
  
  vector<double> sum(N);
  sum[0]=exp[0];
  for(int i=1;i<N;i++){
    sum[i]+=(exp[i]+sum[i-1]);
  }
  
  
  double ans=sum[K-1];
  
  for(int i=0;i<=N-K;i++){
    ans=max(ans,sum[K+i]-sum[i]);
  }
  
  cout<<fixed<<setprecision(10)<<ans<<endl;
}