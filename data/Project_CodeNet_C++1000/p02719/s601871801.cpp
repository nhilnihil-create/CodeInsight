#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  ll N,K;
  cin >> N >> K;
  
  //while(N>K){N = N - K; }
  if(N>K){
    N = N-(((N-K)/K)+1)*K;
  }
  
  //min(N,abs(N-K))
 
  cout << min(N,abs(N-K)) << endl;
  
  return 0;
}