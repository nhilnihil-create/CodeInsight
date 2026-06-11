#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long A, B, C, D;
  cin >> A >> B >> C >> D;

  cout << ((B - ((B / C) + (B / D))) + (B / ((C * D) / gcd(C, D)))) - (((A - 1) - ((A - 1) / C) - ((A - 1) / D)) + ((A - 1) / ((C * D) / gcd(C, D)))) << endl;

  return 0;
}
