#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,K,a;
  cin>>N>>K;
  a=K;
  for(ll i=0;;i++){
    if(a>N){
      cout<<i+1<<endl;
      return 0;
    }
    a=a*K;
  }
}
    
