#include <bits/stdc++.h>
using namespace std;

int main () {
  string S;
  cin >> S;
  int N = S.size();
  long long sum = 0;
  long long A = 0;
  long long B = 0;
  
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '<'){
      A++;
    }
    else if (S.at(i) == '>'){
      B++;
    }
    if (i == N-1 || S.at(i) == '>' && S.at(i+1) == '<'){
      for (int i = 1; i <= max(A,B); i++) {
        sum += i;
        if (min(A,B) > i){
          sum += i;
        }
      }
      A = 0;
      B = 0;
    }
  }
  cout << sum << endl;
}
    
      
   
   