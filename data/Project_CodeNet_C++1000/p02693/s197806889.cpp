#include <bits/stdc++.h>
using namespace std;

int main(){
  int K, A, B;
  cin >> K >> A >> B;
  if(B % K == 0 || A % K == 0 | B / K - A / K >= 1){
    cout << "OK" << "\n";
  }
  else cout << "NG" << "\n";
}