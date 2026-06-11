#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main() {
  int A,B,C,K;
  string ans = "No";
  cin >> A >> B >> C >> K;
  
  rep(i,K){
    if(A<B && B<C) {
      ans = "Yes";
      break;
    }
    if(A>=B) {
      B = B*2;
    } else if(B>=C) {
      C = C*2;
    } 
  }
  if(A<B && B<C) {
      ans = "Yes";
  }
  cout << ans << endl;
  
  return 0;
}