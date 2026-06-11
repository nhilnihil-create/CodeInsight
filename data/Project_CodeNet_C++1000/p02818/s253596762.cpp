#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
  ll A,B,K;
  cin >> A >> B >> K;
  if((A+B)<K) {A=0;B=0;}
  else if(A<K) {B=B+A-K;A=0;}
  else {A=A-K;}
  cout << A << " " << B << endl;
  
  return 0;
}