#include<iostream>
using namespace std;

const int MOD=1000000007;

long long Sum(int N, int k){
  return k*(N-k+1)+1;
}

int main(void){
  long long N,K;
  cin >> N >> K;
  
  long long ans=0;
  
  for (long long i=K; i<=N+1; i++){
    ans += i*(N-i+1)+1;
  }
  
  cout << ans % MOD << endl;
  
  
  return 0;
}