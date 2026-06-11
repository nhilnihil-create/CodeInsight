#include <bits/stdc++.h>
using namespace std;
#define rep(i,A) for(int i = 1;i < A;i++)

int main() {
  int B;
  cin >> B;
  int A = B + 1;
  int sum = 0;
  rep(i,A){
    rep(n,A){
      rep(m,A){
        sum += gcd(gcd(i,n),m);
      }
    }
  }
  cout << sum << endl;
 
}
