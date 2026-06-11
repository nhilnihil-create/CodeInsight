#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  unsigned long N,A,B,ans=0;
  cin >> N >> A >> B;
  
  ans = N/(A+B)*A;
  if(N%(A+B)<A) ans += N % (A+B);
  else ans += A;
  cout << ans << endl;
  
  return 0;
}
