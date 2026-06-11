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
  
    int N,M;
  cin>>N>>M;
  int S[10],C[10];
  for(int i=0;i<M;i++){
    cin>>S[i]>>C[i];
  }
 
  for(int i=0;i<=999;i++) {
    bool flag=true;
    string num=to_string(i);
 
    if(N!=num.size()){
      flag=false;
    }
 
    for(int i=0;i<M;i++) {
      if(num[S[i]-1]-'0'!=C[i]){
        flag=false;
      }
    }
 
    if(flag) {
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}