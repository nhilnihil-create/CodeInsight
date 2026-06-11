#include <bits/stdc++.h>
using namespace std;

int main() {
  int K,A,B,M;
  cin >> K >> A >> B;
  M = (B/K) * K;
  if (M >= A){
    cout << "OK" << endl;
  }
  else{
    cout << "NG" << endl;
  }
}