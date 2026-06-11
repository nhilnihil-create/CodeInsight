#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,K;
  cin>>N>>K;
  ll a=N/K;
  ll b=min(N-a*K,a*K+K-N);
  cout<<b<<endl;
  
  
  
}
