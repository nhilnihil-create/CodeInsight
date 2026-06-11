#include <iostream>
using namespace std;
int main(void){
  int a;
  cin >> a;
  if (a % 2 == 0){
    cout << (double)0.5 << endl;
  } else {
    cout << (double)(a / 2 + 1)  / (double)(a)   << endl;
  }
  return 0;
}