#include <iostream>
#include <vector>
using namespace std;

int main(){
  int K;
  cin >> K;
  vector<int> encountered;
  if (7 % K == 0){
    cout << 1;
    return 0;
  }
  else {
    int modK = 7 % K;
    for (int digit = 2; digit <= K; digit++){
      modK = (modK * 10 + 7) % K;
      if (modK == 0){
        cout << digit;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}