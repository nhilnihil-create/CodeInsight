#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool IsPrime(ll N){
  for (ll i=2; i*i<=N; i++){
    if(N % i == 0) return false;
  }
  return N != 1;
}

int main(){
  ll X;
  cin >> X;
  
  while(!IsPrime(X)) ++X;

  cout << X << endl;
  return 0;
}