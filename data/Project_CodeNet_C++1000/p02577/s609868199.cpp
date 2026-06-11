#include <iostream>
using namespace std;

int main(void){
  char c;
  int md9 = 0;
  
  while (cin >> c){
    md9 += (c-'0');
    md9 %= 9;
  }
  cout << (md9==0?"Yes":"No") << endl;
  return 0;
}