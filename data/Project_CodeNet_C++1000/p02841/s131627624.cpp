#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
  int m1,m2,d1,d2;
  cin >> m1 >> d1 >> m2 >> d2;
  if(m1 == m2){
    cout << 0 << endl;
    return 0;
  }
  cout << 1 << endl;
  return 0;
}