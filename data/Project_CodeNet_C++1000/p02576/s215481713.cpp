#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, X, T, n;
  cin >> N >> X >> T;
  
  if (N%X == 0)
    n = N/X;
  else
    n = N/X+1;
  
  cout << T*n << endl;
}