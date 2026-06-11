#include <bits/stdc++.h>
using namespace std;

int main() { 
  int64_t N, A, B;
  cin >> N >> A >> B;
  
  if(A==0) cout << 0 << endl;
  else{
  int64_t a = N/(A+B)*A;
  int64_t b = min(N%(A+B),A);
  
  cout << a+b << endl;
  }
  
}