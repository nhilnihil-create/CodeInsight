#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  int N,sum=0;
  cin >> N;
  vector<int> X(N);
  rep(i,N) {cin >> X[i]; sum+=X[i];}
  int P=round(sum*1.0/N),S=0;
  rep(i,N) {S+=(X[i]-P)*(X[i]-P);}
  
  cout << S << endl;
  
  return 0;
}
