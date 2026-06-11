#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  int A,B,ans=-1,a1=0,a2=0,b1=0,b2=0;
  cin >> A >> B;
  
  a1 = ceil(A/0.08);
  a2 = (A+1)/0.08;
  b1 = ceil(B/0.1);
  b2 = (B+1)/0.1;
  if(a1<b1 && a2>b1) ans = b1;
  else if(a1>=b1 && a1<b2) ans = a1;
  //cout << a1 << a2 << b1 << b2 << endl;
  cout << ans << endl;
  
  return 0;
}
