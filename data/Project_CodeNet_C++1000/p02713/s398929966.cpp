#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int gcd(int a, int b, int c) {
  int m, n;
  for (int i=1; i<=min(a,b); i++) {
    if (a%i==0 && b%i==0) {m=i;}
  }
  for (int i=1; i<=min(m,c); i++) {
    if (m%i==0 && c%i==0) {n=i;}
  }
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