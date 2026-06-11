#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  string S;
  cin >> N >> S;
  long long R = 0,G = 0,B = 0;
  for (long long i = 0; i < N; i++) {
    if (S.at(i) == 'R')
      R++;
    if (S.at(i) == 'G')
      G++;
    if (S.at(i) == 'B')
      B++;
  }
  long long count = 0;
  for (long long j = 0; j < (N - 3)/2 + 1; j++) {
    for (long long k = 0; k < N - (j*2 + 3) + 1; k++) {
      if(S.at(k) != S.at(k + j + 1) && S.at(k) != S.at(k + 2*j + 2) && S.at(k + 2*j + 2) != S.at(k + j + 1))
        count++;
    }
  }
   
  cout << R*G*B - count << endl;
  
  
  
  
}
