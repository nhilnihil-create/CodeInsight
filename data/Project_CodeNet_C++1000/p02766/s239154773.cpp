#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
int main() {
  int N,K;
  cin >> N >> K;
  int i = 0;
  for(i=0;N>0;i++){
    N /= K;
  }
  cout << i;
}