#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll A,B,K;
  cin >> A >> B >> K;
  if(K<A){
    A-=K;
  }
  else{
    if(K-A<B){
      B-=K-A;
    }
    else{
      B=0;
    }
    A=0;
  }
  cout << A << " " << B << endl;
}