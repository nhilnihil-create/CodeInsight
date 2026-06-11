#include <iostream>
#include <string>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

ll gcd(ll a, ll b){
  if (a % b == 0) return b;
  else return gcd(b, a % b);
}

ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}

int main(){
  ll a, b;
  cin >> a >> b;
  cout << lcm(a, b) << endl;
  
  return 0;
}