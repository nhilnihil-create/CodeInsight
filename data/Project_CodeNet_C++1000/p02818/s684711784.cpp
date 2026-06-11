#include <iostream>
#include <string>
using namespace std;
int main(void){
  long long A, B, K;
  cin >> A >> B >> K;
  long long diff = K - A;
  long long out_A, out_B;
  if(diff > 0){
    if(B-diff>0){
      out_A = 0;
      out_B = B - diff;
    }else{
      out_A = 0;
      out_B = 0;
    }
  }else{
    out_A = A - K;
    out_B = B;
  }
  
  cout << out_A << " " << out_B;
  return 0;
}