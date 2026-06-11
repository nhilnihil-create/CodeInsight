#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll calc_num(ll N, ll C, ll D){
  ll G = gcd(C, D);
  ll L = C/G*D;
  return N - N/C - N/D + N/L;
}

int main(){
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  
  cout << calc_num(B, C, D)-calc_num(A-1, C, D) << endl;
  
  
  return 0;
}