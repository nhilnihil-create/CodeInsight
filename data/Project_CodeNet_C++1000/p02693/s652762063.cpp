#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, A, B;
  cin >> K >> A >> B;
  string flg = "NG";

  for(A; A <= B; A++) {
    if(A % K == 0) {
      flg = "OK";
      break;
    }
  }
  cout << flg << endl;
}