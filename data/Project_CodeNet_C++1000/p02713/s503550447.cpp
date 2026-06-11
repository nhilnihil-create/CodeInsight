#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int gcd(int a, int b, int c) {
  int m, n;
  while (b!=0) {
    m=a%b;
    a=b;
    b=m;
  }
  m=a;
  
  while (c!=0) {
    n=m%c;
    m=c;
    c=n;
  }
  n=m;
  return n;
}


int main() {
  int K, S=0;
  cin >> K;
  for (int i=1; i<=K; i++) {
    for (int j=1; j<=K; j++) {
      for (int k=1; k<=K; k++) {
        S+=gcd(i,j,k);
      }
    }
  }
  cout << S << endl;
}