#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int gcd(long a, long b) {
  if (a%b == 0) {
    return(b);
  }
  else return(gcd(b, a%b));
}

int main() {
  long long A,B;
  cin >> A >> B;
  long long gcdab = gcd(A,B);
  //cout << gcdab << endl;
  long long sum = 1; //最初に1
  for (long long i=2; i*i <= gcdab; i++) {
    if (gcdab % i != 0) continue;
    sum++;
    //cout << i << " " << gcdab << endl;
    while (gcdab%i == 0) {
      gcdab /= i;
    } 
  }
  if (gcdab != 1) sum++;
  cout << sum << endl;
  return 0;
}