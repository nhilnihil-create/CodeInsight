#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll x, ll y){
  if (y == 0) return x;
  else return gcd(y, x % y);
}


int main(){
  ll A, B;
  cin >> A >> B;
  
  cout << A/gcd(A, B)*B << endl;

  return 0;
}