#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
  int main(){
  long long X;
  long long B = 100;
  int Y = 1;
    cin >> X;
    while(1){
      B = B + B/100;
      if(B >= X){
        cout << Y <<endl;
        break;
      }
      Y++;
    }
}