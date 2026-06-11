#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  for(int i = 0; i < N; i++) cin >> A.at(i);
  int64_t mo = 1000;
  int64_t stk = 0;
  
  for(int i = 0; i < N; i++){
    if(stk != 0){
      mo += stk * A.at(i);
      stk = 0;
    }//売り
    
    if(i != N - 1){
      if(A.at(i) < A.at(i+1)){
        stk += (mo / A.at(i));
        mo %= A.at(i);
      }
    }
  }
  
  cout << mo << endl;
}