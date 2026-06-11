#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll gcd(ll a, ll b) {
  return (a % b ? gcd(b, a%b) : b);
}

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  
  ll C_multi = (B)/C - (A-1)/ C, D_multi = B/D - (A-1)/D;
  ll E = gcd(C,D);
  ll F = C * D / E;
  ll CD_multi = (B)/F - (A-1)/ F;
  
  cout << B- A +1 - C_multi - D_multi + CD_multi << endl;
}