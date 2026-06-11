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

vector<pair<long long,long long>> prime_factorize(long long N){
  vector<pair<long long,long long>> res;
  
  for(long long i=2;i*i<=N;i++){
    if(N%i!=0){
    continue;
    }
    
    long long ex=0;
    while(N%i==0){
      ex++;
      N/=i;
    }
    
    res.push_back({i,ex});
  }
  
  if(N!=1){
  res.push_back({N,1});
  }
  
  return res;
}


int main() {
  
  long long N;
  cin>>N;
  
  long long ans=0;
  
  
  if(N%2==1){
    cout<<ans<<endl;
  }
  else{
    long long x=10;
    while(x<=N){
      ans+=N/x;
      x*=5;
    }
    cout<<ans<<endl;
  }
}