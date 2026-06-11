#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long A, B;
  long E;
  long ans;
  cin >> A >> B;
  for(long i = min(A,B); i > 0; i--){
    if(A % i == 0 && B % i == 0){
      E = i;
      break;
    }
    E = 1;
  }
  ans = (A/E) * (B/E) * E;
  cout << ans << endl;
}