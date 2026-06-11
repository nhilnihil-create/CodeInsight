#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if(a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int lcm(int a, int b){
   return a * b / gcd(a, b);
}

int main() {
  int x;
  int ans;
  cin >> x;

  cout << lcm(360, x) / x << endl;
}