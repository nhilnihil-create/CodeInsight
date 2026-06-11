#include "bits/stdc++.h"
using namespace std;
int fun(){
   int A,B,C,K;
  cin >> A >> B >> C >> K;
  if (A > K) return K;
  else if (A+B > K) return A;
  else if (A+B+C > K) return A - (K - A - B);
  else return A - C;
}

int main(){
  cout << fun() << endl;
  return 0;
}