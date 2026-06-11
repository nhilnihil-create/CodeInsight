#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool is_prime(ll x){
  if(x==1) return false;
  else{
    for(int i=2;i*i<=x;i++){
      if(x%i==0) return false;
    }
  return x!=1;
  }
}

int main() {
  ll X;cin>>X;
  
  for(int i=X;i<=100003;i++){
    if(is_prime(i)){
      cout << i << endl;
      return 0;
    }
  }
}
