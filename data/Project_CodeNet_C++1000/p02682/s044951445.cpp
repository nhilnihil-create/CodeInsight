#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  long long int A;
  long long int B;
  long long int C;
  long long int K;
  long long int sum = 0;
  cin>>A;
  cin>>B;
  cin>>C;
  cin>>K;
  if(K != 0){
    //K = K - (min(A,K));
    if(min(A,K) == A){
      sum += (A * 1);
    }else{
      sum += (K * 1);
    }
    K = K - (min(A,K));
  }
  if(K != 0){
    //K = K - (min(B,K));
    if(min(B,K) == B){
      sum += (B * 0);
    }else{
      sum += (K * 0);
    }
    K = K - (min(B,K));
  }
  if(K != 0){
    //K = K - (min(C,K));
    if(min(C,K) == C){
      sum += (C * -1);
    }else{
      sum += (K * -1);
    }
    K = K - (min(C,K));
  }
  cout<<sum<<'\n';
}