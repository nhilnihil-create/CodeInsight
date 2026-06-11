#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,K;
  cin>>N>>K;
 ll X=N/K;
  N-=K*X;
 ll A=abs(N-K);
  cout<<min(A,N)<<endl;
}
 
  
  