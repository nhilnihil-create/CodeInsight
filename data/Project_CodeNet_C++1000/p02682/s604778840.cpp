#include <bits/stdc++.h>
 using namespace std;

int main(){
  long long A,B,C,K;
  cin >> A >> B >> C >> K;

  long long res;
  if (K >= A){
    res = A;
    K -= A;
    if (K >= B){
      K -= B;
      res -= K;
    }
  }
  else
    res = K;
  cout << res << "\n";

  return 0;
}