#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,K;
  cin>>N>>K;
  long long M = K;
  long long ans = 1;
  
  while(N>=M){
    M=M*K;
    ans++;
  }
  cout<<ans<<endl;
}