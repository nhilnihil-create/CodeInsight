#include<bits/stdc++.h>

using namespace std;

int gcd(int m, int n) {
  if (m%n==0) return n;
  else return gcd(n, m%n);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  cout<<360/gcd(360, n)<<"\n";
}