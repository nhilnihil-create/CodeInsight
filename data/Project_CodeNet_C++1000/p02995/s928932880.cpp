#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long A,B;
  long long C,D;
  cin >> A >> B >> C >> D;
  long long count = 0;
  int N = 1;
  int c = C;
  int d = D;
    
  for (int i = 2; i <= 31623; i++) { 
    for (int j = 0; i < 15; j++) { 
      if (c % i == 0 && d % i == 0){
        N *= i;
        c /= i;
        d /= i;
      }
      else {
        break;
      }
    }
  }
  
  if (C == D && N == 1){
    N = C;
  }
  long long M = C*D/N;
  count = B/M - (A-1)/M;

  cout << B - A + 1 - ((B/C - (A-1)/C) + (B/D - (A-1)/D) - count) << endl;
}

