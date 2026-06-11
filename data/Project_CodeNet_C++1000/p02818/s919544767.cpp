#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t A, B, K;
  cin >> A >> B >> K;
  
  int64_t TAK,AOK;//Takahashi, Aoki
  
  if(K<=A){
    TAK = A-K;
    AOK = B;
  }else if(A< K && K<= A+B){
    TAK = 0;
    AOK = B-(K-A);
  }else {
    TAK = 0;
    AOK = 0;
  }
  
  cout << TAK << " " << AOK << endl;
  
}