#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  int A,B,C;
  string ans="Yes";
  cin >> A >> B >> C;
  if(A==B && B== C) ans = "No";
  else if(A!=B && B!=C && C!=A) ans = "No";
  cout << ans << endl;
  
  return 0;
}
